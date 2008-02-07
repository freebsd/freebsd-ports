--- interfaces/blas/C/src/cblas_dgemm.c.orig	2008-01-16 09:20:04.249403699 -0500
+++ interfaces/blas/C/src/cblas_dgemm.c	2008-01-16 09:28:30.250360804 -0500
@@ -146,7 +146,7 @@
  */
    if (A == B && M == N && TA != TB && lda == ldb && beta == 0.0)
    {
-      ATL_dsyrk(CblasUpper, TA, N, K, alpha, A, lda, beta, C, ldc);
+      ATL_dsyrk(CblasUpper, (Order == CblasColMajor)?TA:TB, N, K, alpha, A, lda, beta, C, ldc);
       ATL_dsyreflect(CblasUpper, N, C, ldc);
       return;
    }
