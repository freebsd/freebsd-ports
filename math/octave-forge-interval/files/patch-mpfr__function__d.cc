--- mpfr_function_d.cc.orig	2017-08-20 08:32:14 UTC
+++ mpfr_function_d.cc
@@ -217,7 +217,11 @@ void nthroot (
   for (octave_idx_type i = 0; i < n; i ++)
     {
       mpfr_set_d (mp, arg1.elem (i), MPFR_RNDZ);
+#ifdef OCTAVE_ENSURE_LONG_DOUBLE_OPERATIONS_ARE_NOT_TRUNCATED
+      mpfr_root (mp, mp, (unsigned long long)arg2.elem(i), rnd);
+#else
       mpfr_root (mp, mp, arg2.elem(i), rnd);
+#endif
       arg1.elem (i) = mpfr_get_d (mp, rnd);
     }
 
