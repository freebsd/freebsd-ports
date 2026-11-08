-- Use GSL spherical Bessel functions instead of std::sph_bessel, which is
-- not provided by FreeBSD's libc++ even in C++17 mode.

--- src/mathf.cpp.orig	2026-09-30 19:02:20 UTC
+++ src/mathf.cpp
@@ -28,6 +28,8 @@ extern "C" {
 extern "C" {
   // For the regularized incomplete gamma function (no std equivalent in C++17)
 #include <gsl/gsl_sf_gamma.h>
+  // For spherical Bessel functions (no libc++ equivalent in C++17)
+#include <gsl/gsl_sf_bessel.h>
   // For cubic spline interpolation
 #include <gsl/gsl_spline.h>
   // For confluent hypergeometric 1F1 (no std equivalent in C++17)
@@ -123,7 +125,7 @@ double bessel_jl(int l, double x) {
     return j;
   }
 
-  return std::sph_bessel(l, x);
+  return gsl_sf_bessel_jl(l, x);
 }
 
 double boysF(int m, double x) {
