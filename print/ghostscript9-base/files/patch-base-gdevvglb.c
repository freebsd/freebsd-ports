--- base/gdevvglb.c.orig	2011-07-17 19:56:33.000000000 +0900
+++ base/gdevvglb.c	2011-07-17 19:57:10.000000000 +0900
@@ -367,12 +367,3 @@
     }
     return 0;
 }
-
-#ifdef GS_DEVS_SHARED
-extern void gs_lib_register_device(const gx_device *dev);
-void
-gs_shared_init(void)
-{
-  gs_lib_register_device(&gs_vgalib_device);
-}
-#endif
