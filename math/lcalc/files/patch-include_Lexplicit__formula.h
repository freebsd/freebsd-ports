--- include/Lexplicit_formula.h.orig	2012-08-08 21:21:55 UTC
+++ include/Lexplicit_formula.h
@@ -1,4 +1,5 @@
 // This file mainly due to Kevin McGown, with modifications by Michael Rubinstein
+// Patches borrowed from SageMath.
 
 #ifndef Lexplicit_formula_H
 #define Lexplicit_formula_H
@@ -25,7 +26,7 @@ int L_function <ttype>::
 dirichlet_coeffs_log_diff(int num_coeffs, Complex *c)
 {
 
-  Complex b[num_coeffs+1];
+  std::vector<Complex> b(num_coeffs+1);
   int j, n, d1, ind;
   Complex total, total2, temp;
 
