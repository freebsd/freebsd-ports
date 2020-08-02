--- nf_elem/mul.c.orig	2020-06-13 18:49:26 UTC
+++ nf_elem/mul.c
@@ -127,7 +127,7 @@ void _nf_elem_mul_red(nf_elem_t a, const nf_elem_t b, 
                
                _fmpz_vec_set(r, NF_ELEM_NUMREF(a), plen);
 
-#if __FLINT_RELEASE == 20600
+#if __FLINT_RELEASE >= 20600
                _fmpz_poly_divrem(q, NF_ELEM_NUMREF(a), r, plen, 
                   fmpq_poly_numref(nf->pol), len, 0);
 #else
