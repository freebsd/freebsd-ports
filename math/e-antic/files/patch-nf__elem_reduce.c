--- nf_elem/reduce.c.orig	2020-06-13 18:49:26 UTC
+++ nf_elem/reduce.c
@@ -80,7 +80,7 @@ void _nf_elem_reduce(nf_elem_t a, const nf_t nf)
                
                _fmpz_vec_set(r, NF_ELEM_NUMREF(a), plen);
 
-#if __FLINT_RELEASE == 20600
+#if __FLINT_RELEASE >= 20600
                _fmpz_poly_divrem(q, NF_ELEM_NUMREF(a), r, plen, 
                   fmpq_poly_numref(nf->pol), len, 0);
 #else
