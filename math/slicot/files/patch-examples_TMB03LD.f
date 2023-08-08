--- examples/TMB03LD.f.orig	2022-05-27 14:40:35 UTC
+++ examples/TMB03LD.f
@@ -26,6 +26,8 @@
      $                   DWORK( LDWORK ), FG( LDFG, NMAX/2+1 ),
      $                   Q( LDQ, 2*NMAX )
 *
+      LOGICAL            LSAME
+      EXTERNAL           LSAME
 *     .. External Subroutines ..
       EXTERNAL           MB03LD
 *
