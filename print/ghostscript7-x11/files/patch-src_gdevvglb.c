--- src/gdevvglb.c.orig	2003-01-17 00:49:02 UTC
+++ src/gdevvglb.c
@@ -373,3 +373,12 @@ vgalib_put_params(gx_device * dev, gs_pa
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
