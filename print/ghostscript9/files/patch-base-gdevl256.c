--- base/gdevl256.c.orig	2011-07-17 19:57:32.000000000 +0900
+++ base/gdevl256.c	2011-07-17 19:57:39.000000000 +0900
@@ -302,12 +302,3 @@
     gl_line(x0, y0, x1, y1, color);
     return 0;
 }
-
-#ifdef GS_DEVS_SHARED
-extern void gs_lib_register_device(const gx_device *dev);
-void
-gs_shared_init(void)
-{
-  gs_lib_register_device(&gs_lvga256_device);
-}
-#endif
