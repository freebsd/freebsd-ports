http://math-atlas.sourceforge.net/errata.html
Error in complex gemm for A*A^T.

--- src/blas/gemm/ATL_cmmJIK.c	Mon Dec 22 09:08:00 2003
+++ src/blas/gemm/ATL_cmmJIK.c	Wed Mar  7 00:26:46 2007
@@ -190,7 +190,7 @@
          pA = ATL_AlignPtr(vB);
          if (TA == AtlasNoTrans)
             Mjoin(PATL,row2blkT2_a1)(M, K, A, lda, pA, alpha);
-         else Mjoin(PATL,col2blk_a1)(K, M, A, lda, pA, alpha);
+         else Mjoin(PATL,col2blk2_a1)(K, M, A, lda, pA, alpha);
 /*
  *       Can't write directly to C if alpha is not one
  */
