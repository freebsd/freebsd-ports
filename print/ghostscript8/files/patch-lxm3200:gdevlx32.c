--- lxm3200/gdevlx32.c.orig	Wed Apr 23 01:06:20 2003
+++ lxm3200/gdevlx32.c	Thu May 15 08:24:08 2003
@@ -422,9 +422,11 @@
  * of the nearest color.
  */
 private gx_color_index
-lxm3200_map_rgb_color(gx_device *dev,	gx_color_value r, 
-											gx_color_value g, gx_color_value b)
+lxm3200_map_rgb_color(gx_device *dev,	const gx_color_value cv[]) 
 {
+	gx_color_value r = cv[0];
+	gx_color_value g = cv[1];
+	gx_color_value b = cv[2];
 	gx_color_index col;
 	int c, m, y;
 
@@ -479,7 +481,7 @@
 			break;
 
 		default:
-			col = gdev_prn_map_rgb_color(dev, r, g, b);
+			col = gdev_prn_map_rgb_color(dev, cv);
 			break;
 	}
 
