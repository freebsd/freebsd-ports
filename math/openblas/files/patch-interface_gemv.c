--- interface/gemv.c.orig	2021-07-14 00:09:14 UTC
+++ interface/gemv.c
@@ -202,11 +202,6 @@ void CNAME(enum CBLAS_ORDER order,
 
   if (alpha == ZERO) return;
 
-  if (trans == 0 && incx == 1 && incy == 1 && m*n < 2304 *GEMM_MULTITHREAD_THRESHOLD) {
-    GEMV_N(m, n, 0, alpha, a, lda, x, incx, y, incy, NULL);
-    return;
-  }    
-
   IDEBUG_START;
 
   FUNCTION_PROFILE_START();
