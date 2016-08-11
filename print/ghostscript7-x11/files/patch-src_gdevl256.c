--- src/gdevl256.c.orig	2003-01-17 00:49:00 UTC
+++ src/gdevl256.c
@@ -307,3 +307,12 @@ lvga256_draw_line(gx_device * dev, int x
     gl_line(x0, y0, x1, y1, color);
     return 0;
 }
+
+#ifdef GS_DEVS_SHARED
+extern void gs_lib_register_device(const gx_device *dev);
+void
+gs_shared_init(void)
+{
+  gs_lib_register_device(&gs_lvga256_device);
+}
+#endif
