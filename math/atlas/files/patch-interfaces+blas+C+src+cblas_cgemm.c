--- interfaces/blas/C/src/cblas_cgemm.c.orig	2008-01-16 09:19:46.679079259 -0500
+++ interfaces/blas/C/src/cblas_cgemm.c	2008-01-16 09:26:48.761814634 -0500
@@ -148,7 +148,7 @@
    if (A == B && M == N && TA != TB && lda == ldb && *bet == 0.0 &&
        bet[1] == 0.0 && TA != CblasConjTrans && TB != CblasConjTrans)
    {
-      ATL_csyrk(CblasUpper, TA, N, K, alpha, A, lda, beta, C, ldc);
+      ATL_csyrk(CblasUpper, (Order == CblasColMajor)?TA:TB, N, K, alpha, A, lda, beta, C, ldc);
       ATL_csyreflect(CblasUpper, N, C, ldc);
       return;
    }
