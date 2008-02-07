--- interfaces/blas/C/src/cblas_zgemm.c.orig	2008-01-16 09:20:22.356646659 -0500
+++ interfaces/blas/C/src/cblas_zgemm.c	2008-01-16 09:31:52.424584623 -0500
@@ -148,7 +148,7 @@
    if (A == B && M == N && TA != TB && lda == ldb && *bet == 0.0 &&
        bet[1] == 0.0 && TA != CblasConjTrans && TB != CblasConjTrans)
    {
-      ATL_zsyrk(CblasUpper, TA, N, K, alpha, A, lda, beta, C, ldc);
+      ATL_zsyrk(CblasUpper, (Order == CblasColMajor)?TA:TB, N, K, alpha, A, lda, beta, C, ldc);
       ATL_zsyreflect(CblasUpper, N, C, ldc);
       return;
    }
