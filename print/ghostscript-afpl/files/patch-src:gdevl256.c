--- src/gdevl256.c.orig	Fri Feb 22 07:24:51 2002
+++ src/gdevl256.c	Tue May 20 03:08:15 2003
@@ -147,10 +147,12 @@
 /* for compatibility with the older display modes: */
 /* these are indexed as 0.0.R0.G0.B0.R1.G1.B1. */
 gx_color_index
-lvga256_map_rgb_color(gx_device * dev, gx_color_value r, gx_color_value g,
-		      gx_color_value b)
+lvga256_map_rgb_color(gx_device * dev, const gx_color_value cv[])
 {
 #define cv_bits(v,n) (v >> (gx_color_value_bits - n))
+    gx_color_value r = cv[0];
+    gx_color_value g = cv[1];
+    gx_color_value b = cv[2];
     ushort r5 = cv_bits(r, 5), g5 = cv_bits(g, 5), b5 = cv_bits(b, 5);
     static const byte cube_bits[32] =
     {0, 128, 128, 128, 128, 128, 128, 128, 128, 128,
