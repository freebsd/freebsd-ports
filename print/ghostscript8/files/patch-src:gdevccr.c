--- src/gdevccr.c.orig	Fri Feb 22 07:24:51 2002
+++ src/gdevccr.c	Sun Nov 10 22:38:51 2002
@@ -112,8 +112,11 @@
 /* ------ Color mapping routines ------ */
 /* map an rgb color to a ccr cmy bitmap */
 private gx_color_index
-ccr_map_rgb_color(gx_device *pdev, ushort r, ushort g, ushort b)
+ccr_map_rgb_color(gx_device *pdev, const ushort cv[])
 {
+  ushort r = cv[0];
+  ushort g = cv[1];
+  ushort b = cv[2];
   register int shift = gx_color_value_bits - 1;
   r>>=shift;
   g>>=shift;
