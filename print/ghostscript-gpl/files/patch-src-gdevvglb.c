--- src/gdevvglb.c.orig	Mon Jun  4 01:15:47 2007
+++ src/gdevvglb.c	Mon Jun  4 01:18:45 2007
@@ -149,10 +149,13 @@
 }
 
 private gx_color_index
-vgalib_map_rgb_color(gx_device * dev, gx_color_value red,
-		     gx_color_value green, gx_color_value blue)
+vgalib_map_rgb_color(gx_device * dev, const gx_color_value cv[])
 {
-    return pc_4bit_map_rgb_color(dev, red, green, blue);
+	gx_color_value r = cv[0];
+	gx_color_value g = cv[1];
+	gx_color_value b = cv[2];
+
+    return pc_4bit_map_rgb_color(dev, cv);
 }
 
 private int
