--- src/gdevmgr.c.orig	Sun Jun 16 14:48:55 2002
+++ src/gdevmgr.c	Sun Nov 10 22:52:19 2002
@@ -364,9 +364,11 @@
 /* (1/6, 1/2, and 5/6), instead of the obvious 8x8x4. */
 
 gx_color_index
-mgr_8bit_map_rgb_color(gx_device *dev, gx_color_value r, gx_color_value g,
-  gx_color_value b)
-{	uint rv = r / (gx_max_color_value / 7 + 1);
+mgr_8bit_map_rgb_color(gx_device *dev, const gx_color_value cv[])
+{	gx_color_value r = cv[0];
+	gx_color_value g = cv[1];
+	gx_color_value b = cv[2];
+	uint rv = r / (gx_max_color_value / 7 + 1);
 	uint gv = g / (gx_max_color_value / 7 + 1);
 	uint bv = b / (gx_max_color_value / 7 + 1);
 	return (gx_color_index)
