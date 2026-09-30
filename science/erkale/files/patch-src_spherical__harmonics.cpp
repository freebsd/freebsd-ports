-- Use GSL spherical Legendre functions instead of std::sph_legendre, which
-- is not provided by FreeBSD's libc++ even in C++17 mode.

--- src/spherical_harmonics.cpp.orig	2026-09-30 19:02:20 UTC
+++ src/spherical_harmonics.cpp
@@ -21,10 +21,11 @@
 
 #include <cmath>
 #include <cfloat>
+#include <gsl/gsl_sf_legendre.h>
 
 std::complex<double> spherical_harmonics(int l, int m, double theta, double phi) {
   /* Calculate value of spherical harmonic Y_{lm} = N_{lm} P_{lm} (\cos \theta) e^{i m \phi} */
-  if(m<0) { // std::sph_legendre requires m >= 0. Use the identity {Y_l}^{-m} = (-1)^m \overline{ {Y_l}^{m} }
+  if(m<0) { // GSL's spherical Legendre function requires m >= 0. Use the identity {Y_l}^{-m} = (-1)^m \overline{ {Y_l}^{m} }
     return conj(pow(-1.0,m)*spherical_harmonics(l,-m,theta,phi));
   }
 
@@ -34,14 +35,14 @@ std::complex<double> spherical_harmonics(int l, int m,
   ylm=pow(M_E,std::complex<double>(0.0,m*phi)); // e^(im phi)
   // and then plug in the normalized associated Legendre polynomial,
   // which already includes the Condon-Shortley phase factor.
-  ylm*=std::sph_legendre(l,m,theta);
+  ylm*=gsl_sf_legendre_sphPlm(l,m,std::cos(theta));
 
   return ylm;
 }
 
 double solid_harmonics(int l, int m, double theta, double phi) {
   // Value of normalized Legendre polynomial is
-  double Plm=std::sph_legendre(l,abs(m),theta);
+  double Plm=gsl_sf_legendre_sphPlm(l,std::abs(m),std::cos(theta));
 
   if(m>0)
     return sqrt(2)*Plm*cos(m*phi);
