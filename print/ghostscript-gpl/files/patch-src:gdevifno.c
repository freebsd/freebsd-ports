--- src/gdevifno.c.orig	Sun Jun 16 14:48:55 2002
+++ src/gdevifno.c	Sun Nov 10 22:49:32 2002
@@ -99,8 +99,10 @@
  * rgb and color map entries
  */
 private gx_color_index 
-inferno_rgb2cmap(gx_device *dev, gx_color_value red,
-  gx_color_value green, gx_color_value blue) {
+inferno_rgb2cmap(gx_device *dev, const gx_color_value cv[]) {
+	gx_color_value red = cv[0];
+	gx_color_value green = cv[1];
+	gx_color_value blue = cv[2];
 	int shift;
 	inferno_device *bdev = (inferno_device*) dev;
 	int nbits = bdev->nbits;
