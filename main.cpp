#include <iostream>
#include "black_scholes.h"
#include "interval_bisection.h"
using std::cout;
using std::cin;
using std::endl;

int main() {
  double S = 100.0;  // Underlying spot price
  double K = 100.0;  // Strike price
  double r = 0.05;   // Risk-free rate (5%)
  double T = 1.0;    // One year until expiry
  double C_M = 10.5; // Option market price

  // Create the Black-Scholes Call functor
  BlackScholesCall bsc1(S, K, r, T);
  BlackScholesCall bsc2(S, K, r, T);
  // BlackScholesCall bsc3(S, K, r, T);

  // Interval Bisection parameters
  double low_vol1 = 0.05;
  double high_vol1 = 0.35;
  double episilon1 = 0.001;
  double low_vol2 = 0.10;
  double high_vol2 = 0.50;
  double episilon2 = 0.005;

  // Calculate the implied volatility
  double a = interval_bisection(C_M, low_vol1, high_vol1, episilon1, bsc1);
  double b = interval_bisection(C_M, low_vol2, high_vol2, episilon2, bsc2);
  // double c = interval_bisection(C_M, low_vol, high_vol, episilon, bsc3);

  // Output the values
  cout << "Implied Volatility for Option: " << a << endl;
  cout << "Implied Volatility for Option: " << b << endl;
  // cout << "Implied Volatility for Option: " << c << endl;

  return 0;
} 