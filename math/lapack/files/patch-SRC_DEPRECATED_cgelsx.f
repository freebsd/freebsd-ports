--- SRC/DEPRECATED/cgelsx.f.orig	2024-12-03 11:39:11 UTC
+++ SRC/DEPRECATED/cgelsx.f
@@ -364,8 +364,8 @@
 *
 *     B(1:M,1:NRHS) := Q**H * B(1:M,1:NRHS)
 *
-      CALL CUNM2R( 'Left', 'Conjugate transpose', M, NRHS, MN, A, LDA,
-     $             WORK( 1 ), B, LDB, WORK( 2*MN+1 ), INFO )
+      CALL CUNM2R( 'Left', 'Conjugate transpose', M, NRHS, MN, A,
+     $              LDA, WORK( 1 ), B, LDB, WORK( 2*MN+1 ), INFO )
 *
 *     workspace NRHS
 *
