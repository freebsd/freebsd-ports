--- src/sis_driver.c.orig	2015-09-23 09:54:07.196489000 +0200
+++ src/sis_driver.c	2015-09-23 09:56:45.740035000 +0200
@@ -9390,7 +9390,7 @@ SISMergedPointerMoved(SCRN_ARG_TYPE arg,
 #if GET_ABI_MAJOR(ABI_XINPUT_VERSION) >= 15
         {
             double dx = x, dy = y;
-            miPointerSetPosition(inputInfo.pointer, Absolute, &dx, &dy);
+            miPointerSetPosition(inputInfo.pointer, Absolute, &dx, &dy, NULL, NULL);
             x = (int)dx;
             y = (int)dy;
         }
