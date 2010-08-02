--- base/gdevl256.c.orig	2007-09-25 22:31:24.000000000 +0900
+++ base/gdevl256.c	2010-08-01 23:05:56.000000000 +0900
@@ -143,9 +143,12 @@
 /* for compatibility with the older display modes: */
 /* these are indexed as 0.0.R0.G0.B0.R1.G1.B1. */
 gx_color_index
-lvga256_map_rgb_color(gx_device * dev, gx_color_value r, gx_color_value g,
-		      gx_color_value b)
+lvga256_map_rgb_color(gx_device * dev, const gx_color_value cv[])
 {
+	gx_color_value r = cv[0];
+	gx_color_value g = cv[1];
+	gx_color_value b = cv[2];
+
 #define cv_bits(v,n) (v >> (gx_color_value_bits - n))
     ushort r5 = cv_bits(r, 5), g5 = cv_bits(g, 5), b5 = cv_bits(b, 5);
     static const byte cube_bits[32] =
@@ -301,12 +304,3 @@
     gl_line(x0, y0, x1, y1, color);
     return 0;
 }
-
-#ifdef GS_DEVS_SHARED
-extern void gs_lib_register_device(const gx_device *dev);
-void
-gs_shared_init(void)
-{
-  gs_lib_register_device(&gs_lvga256_device);
-}
-#endif
