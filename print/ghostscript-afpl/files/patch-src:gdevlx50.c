--- src/gdevlx50.c.orig	Thu May 15 07:38:07 2003
+++ src/gdevlx50.c	Thu May 15 08:02:58 2003
@@ -2603,9 +2603,12 @@
 
 /* Map CMYK to color. */
 private gx_color_index
-lx5000_map_cmyk_color(gx_device * dev, gx_color_value cyan,
-	gx_color_value magenta, gx_color_value yellow, gx_color_value black)
+lx5000_map_cmyk_color(gx_device * dev, const gx_color_value cv[])
 {
+    gx_color_value cyan = cv[0];
+    gx_color_value magenta = cv[1];
+    gx_color_value yellow = cv[2];
+    gx_color_value black = cv[3];
     int bpc = dev->color_info.depth / 4;
     int drop = sizeof(gx_color_value) * 8 - bpc;
     gx_color_index color =
