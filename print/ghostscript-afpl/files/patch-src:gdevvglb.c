--- src/gdevvglb.c.orig	Fri Feb 22 07:24:52 2002
+++ src/gdevvglb.c	Tue May 20 23:57:29 2003
@@ -152,10 +152,12 @@
 }
 
 private gx_color_index
-vgalib_map_rgb_color(gx_device * dev, gx_color_value red,
-		     gx_color_value green, gx_color_value blue)
+vgalib_map_rgb_color(gx_device * dev, const gx_color_value cv[])
 {
-    return pc_4bit_map_rgb_color(dev, red, green, blue);
+    gx_color_value red = cv[0];
+    gx_color_value green = cv[1];
+    gx_color_value blue = cv[2];
+    return pc_4bit_map_rgb_color(dev, cv);
 }
 
 private int
