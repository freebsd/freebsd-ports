--- Arpack/second.f~	2005-07-06 20:23:48.000000000 +0900
+++ Arpack/second.f	2007-10-29 13:31:08.000000000 +0900
@@ -21,7 +21,7 @@
 *     ..
 *     .. External Functions ..
       REAL               ETIME
-      EXTERNAL           ETIME
+      INTRINSIC          ETIME
 *     ..
 *     .. Executable Statements ..
 *
