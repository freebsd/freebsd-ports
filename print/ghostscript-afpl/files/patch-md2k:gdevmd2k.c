--- md2k/gdevmd2k.c.orig	Sun May  2 14:07:57 1999
+++ md2k/gdevmd2k.c	Fri Nov  8 07:29:13 2002
@@ -638,11 +638,13 @@
     (k) = gx_bits_to_color_value((v) & ((1 << (b)) - 1), (b))
 
 private gx_color_index
-alps_map_cmyk_color(gx_device* pdev,
-		    gx_color_value c, gx_color_value m,
-		    gx_color_value y, gx_color_value k)
+alps_map_cmyk_color(gx_device* pdev, const gx_color_value cv[])
 {
     gx_color_index color;
+    gx_color_value c = cv[0];
+    gx_color_value m = cv[1];
+    gx_color_value y = cv[2];
+    gx_color_value k = cv[3];
 
     switch (pdev->color_info.depth) {
     case 1:
@@ -675,10 +677,12 @@
 }
 
 private gx_color_index
-alps_map_cmy_color(gx_device* pdev,
-		   gx_color_value c, gx_color_value m,
-		   gx_color_value y, gx_color_value k)
+alps_map_cmy_color(gx_device* pdev, const gx_color_value cv[])
 {
+    gx_color_value c = cv[0];
+    gx_color_value m = cv[1];
+    gx_color_value y = cv[2];
+    gx_color_value k = cv[3];
     int nbits = pdev->color_info.depth;
     ulong weight = ((gx_max_color_value - k) << 10) / gx_max_color_value;
     c = ((c * weight) >> 10) + k;
@@ -694,10 +698,12 @@
 /* Mapping of RGB colors to gray values. */
 
 private gx_color_index
-alps_map_rgb_color(gx_device *pdev,
-		   gx_color_value r, gx_color_value g, gx_color_value b)
+alps_map_rgb_color(gx_device *pdev, const gx_color_value cv[])
 {
 
+  gx_color_value r = cv[0];
+  gx_color_value g = cv[1];
+  gx_color_value b = cv[2];
   if (gx_color_value_to_byte(r & g & b) == 0xff) {
       return (gx_color_index) 0;	/* White */
   } else {
