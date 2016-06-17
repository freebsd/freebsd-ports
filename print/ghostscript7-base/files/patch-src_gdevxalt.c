--- src/gdevxalt.c.orig	2015-08-22 01:42:12.291619000 +0900
+++ src/gdevxalt.c	2015-08-22 01:42:53.871222000 +0900
@@ -30,6 +30,7 @@
 #include "gdevx.h"
 
 extern const gx_device_X gs_x11_device;
+extern const gx_device_X gs_x11alpha_device;
 
 /*
  * Define a forwarding device with a cache for the first 16 colors,
@@ -957,3 +958,20 @@
     rgb[2] = ((color >> 11) & 0x3ff) * gx_max_color_value / 0x3ff;
     return -1;
 }
+
+#ifdef GS_DEVS_SHARED
+extern void gs_lib_register_device(const gx_device *dev);
+void
+gs_shared_init(void)
+{
+  gs_lib_register_device(&gs_x11_device);
+  gs_lib_register_device(&gs_x11alpha_device);
+  gs_lib_register_device(&gs_x11cmyk_device);
+  gs_lib_register_device(&gs_x11cmyk2_device);
+  gs_lib_register_device(&gs_x11cmyk4_device);
+  gs_lib_register_device(&gs_x11cmyk8_device);
+  gs_lib_register_device(&gs_x11gray2_device);
+  gs_lib_register_device(&gs_x11gray4_device);
+  gs_lib_register_device(&gs_x11mono_device);
+}
+#endif
