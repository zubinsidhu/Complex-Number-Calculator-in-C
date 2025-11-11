/*
 * Homework 4
 * Zubin Sidhu
 * CS240, Spring 2025
 * Purdue University
 */

#include "hw4.h"

#include <math.h>

/*
 * Add Complex - Adds the fields of two complex variables together and returns
 * a complex value representing the sum.
 */

complex_t add_complex(complex_t first_complex, complex_t second_complex) {
  complex_t result = {0, 0};
  result.x = first_complex.x + second_complex.x;
  result.y = first_complex.y + second_complex.y;
  return result;
} /* add_complex() */

/*
 * Neg Complex - Returns the negative form of the x and y values of the complex
 * number argument.
 */

complex_t neg_complex(complex_t complex_num) {
  complex_t result = {0, 0};
  result.x = -1 * complex_num.x;
  result.y = -1 * complex_num.y;
  return result;
} /* neg_complex() */

/*
 * Sub Complex - Subtracts the second complex number from the first complex
 * number and returns the difference.
 */

complex_t sub_complex(complex_t first_complex, complex_t second_complex) {
  return add_complex(first_complex, neg_complex(second_complex));
} /* sub_complex() */

/*
 * Dot Complex - Finds the product of two complex number's corresponding
 * arguments and returns the sum of the two products
 */

double dot_complex(complex_t first_complex, complex_t second_complex) {
  double product_x = first_complex.x * second_complex.x;
  double product_y = first_complex.y * second_complex.y;
  return (product_x + product_y);
} /* dot_complex() */

/*
 * Inverse Complex - Returns the reciprocal of the complex number where
 * the reciprocal is calculated by dividing each of its components by the square
 * of the magnitude of the complex number and negating the imaginary part
 */

complex_t inv_complex(complex_t complex_num) {
  complex_t result = {0, 0};
  double magnitude = sqrt(complex_num.x * complex_num.x +
                          complex_num.y * complex_num.y);
  result.x = complex_num.x / (magnitude * magnitude);
  result.y = -1 * (complex_num.y / (magnitude * magnitude));
  return result;
} /* inv_complex() */

/*
 * Multiply Complex - Returns the product of two complex numbers where the
 * complex product is given by (x1 * x2 – y1 * y2) + (x1 * y2 + y1 * x2) * i
 */

complex_t mul_complex(complex_t first_complex, complex_t second_complex) {
  complex_t result = {0, 0};
  result.x = first_complex.x * second_complex.x -
             first_complex.y * second_complex.y;
  result.y = first_complex.x * second_complex.y +
             first_complex.y * second_complex.x;
  return result;
} /* mul_complex() */

/*
 * Divide Complex - Returns the complex division of the first complex number
 * by the second complex number.
 */

complex_t div_complex(complex_t first_complex, complex_t second_complex) {
  return mul_complex(first_complex, inv_complex(second_complex));
} /* div_complex() */

/*
 * Exponential of Complex - Returns the complex exponential of a complex
 * number which is calculated by e^x * (cos(y) + i * sin(y)).
 */

complex_t exp_complex(complex_t complex_num) {
  complex_t result = {0, 0};
  double exp_x = exp(complex_num.x);
  result.x = exp_x * cos(complex_num.y);
  result.y = exp_x * sin(complex_num.y);
  return result;
} /* exp_complex() */

/*
 * Mandelbrot - Calculates the Mandelbrot iteration count for a given complex
 * number C. It initializes Z to 0 and then repeatedly computes Z = Z^2 + C
 * until the magnitude of Z (|Z|) is at least 2.0 or MAX_MANDELBROT iterations
 * has been reached.
 */

int mandelbrot(complex_t complex_num) {
  int iterations = 0;
  complex_t z = {0, 0};

  while ((iterations < MAX_MANDELBROT) && (dot_complex(z, z) < 4.0)) {
    z = add_complex(mul_complex(z, z), complex_num);
    iterations++;
  }
  return iterations;
} /* mandelbrot() */
