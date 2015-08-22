--- src/gdevvglb.c.orig	2015-08-22 01:41:20.966252000 +0900
+++ src/gdevvglb.c	2015-08-22 01:41:35.725091000 +0900
@@ -373,3 +373,12 @@
     }
     return 0;
 }
+
+#ifdef GS_DEVS_SHARED
+extern void gs_lib_register_device(const gx_device *dev);
+void
+gs_shared_init(void)
+{
+  gs_lib_register_device(&gs_vgalib_device);
+}
+#endif
