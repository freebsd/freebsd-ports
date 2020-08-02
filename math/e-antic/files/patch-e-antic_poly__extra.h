--- e-antic/poly_extra.h.orig	2020-06-13 18:49:26 UTC
+++ e-antic/poly_extra.h
@@ -262,7 +262,7 @@ void fmpz_poly_evaluate_at_one(fmpz_t res, fmpz * p, s
     return _fmpz_vec_sum(res, p, len);
 }
 
-#if __FLINT_RELEASE != 20600
+#if __FLINT_RELEASE < 20600
 static __inline__
 double fmpq_get_d(const fmpq_t q)
 {
@@ -346,14 +346,14 @@ void _fmpz_poly_num_real_roots_sturm(slong * n_neg, sl
 
 void fmpz_poly_product_roots_fmpq_vec(fmpz_poly_t poly, const fmpq * xs, slong n);
 
-#elif __FLINT_RELEASE == 20503 || __FLINT_RELEASE == 20600
+#elif __FLINT_RELEASE > 20502
 
 #define _EANTIC_FIXED_fmpq_poly_get_str_pretty _fmpq_poly_get_str_pretty
 #define EANTIC_FIXED_fmpq_poly_get_str_pretty fmpq_poly_get_str_pretty
 
 #else
 
-#error "Invalid flint release: e-antic needs flint-2.5.2, flint-2.5.3 or flint-2.6.0"
+#error "Invalid flint release: e-antic needs flint >= 2.5.2"
 
 #endif
 
