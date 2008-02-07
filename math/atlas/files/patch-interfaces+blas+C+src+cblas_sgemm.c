--- interfaces/blas/C/src/cblas_sgemm.c.orig	2008-01-16 09:20:16.739501184 -0500
+++ interfaces/blas/C/src/cblas_sgemm.c	2008-01-16 09:29:45.572899283 -0500
@@ -146,7 +146,7 @@
  */
    if (A == B && M == N && TA != TB && lda == ldb && beta == 0.0)
    {
-      ATL_ssyrk(CblasUpper, TA, N, K, alpha, A, lda, beta, C, ldc);
+      ATL_ssyrk(CblasUpper, (Order == CblasColMajor)?TA:TB, N, K, alpha, A, lda, beta, C, ldc);
       ATL_ssyreflect(CblasUpper, N, C, ldc);
       return;
    }
