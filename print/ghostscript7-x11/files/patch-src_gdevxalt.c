--- src/gdevxalt.c.orig	2003-01-17 00:49:02 UTC
+++ src/gdevxalt.c
@@ -30,6 +30,7 @@
 #include "gdevx.h"
 
 extern const gx_device_X gs_x11_device;
+extern const gx_device_X gs_x11alpha_device;
 
 /*
  * Define a forwarding device with a cache for the first 16 colors,
@@ -957,3 +958,20 @@ x_rg32x_alt_map_color(gx_device * dev, g
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
