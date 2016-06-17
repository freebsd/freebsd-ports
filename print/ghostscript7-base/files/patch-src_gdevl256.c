--- src/gdevl256.c.orig	2015-08-22 01:40:41.895138000 +0900
+++ src/gdevl256.c	2015-08-22 01:40:56.016022000 +0900
@@ -307,3 +307,12 @@
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
