--- src/gdevvglb.c.orig	Tue Sep 25 22:31:24 2007
+++ src/gdevvglb.c	Sat Nov 24 23:00:49 2007
@@ -149,10 +149,13 @@
 }
 
 static gx_color_index
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
 
 static int
