-- Use GSL Legendre polynomials instead of std::legendre, which is not
-- provided by FreeBSD's libc++ even in C++17 mode.

--- src/tempered.cpp.orig	2026-09-30 19:02:20 UTC
+++ src/tempered.cpp
@@ -18,6 +18,7 @@
 
 #include "tempered.h"
 #include <cmath>
+#include <gsl/gsl_sf_legendre.h>
 
 // Construct even-tempered set of exponents
 arma::vec eventempered_set(double alpha, double beta, int Nf) {
@@ -67,7 +68,7 @@ arma::mat legendre_P_mat(int Nprim, int kmax) {
 
     // Store values P_0, P_1, ..., P_{kmax-1}
     for(int k=0;k<kmax;k++)
-      Pk(j-1,k)=std::legendre(k, arg);
+      Pk(j-1,k)=gsl_sf_legendre_Pl(k, arg);
   }
 
   return Pk;
