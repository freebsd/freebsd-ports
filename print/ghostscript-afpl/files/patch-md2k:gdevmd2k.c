--- md2k/gdevmd2k.c.orig	Sun May  2 14:07:57 1999
+++ md2k/gdevmd2k.c	Fri Dec 17 19:10:22 2004
@@ -495,7 +495,7 @@
     int i, j;
 
     /* allocate memory */
-    work = (byte *)gs_malloc(3+sizeof(int), line_size,
+    work = (byte *)gs_malloc(pdev->memory, 3+sizeof(int), line_size,
 			     "alps_print_page(work)");
     if (work == 0)
 	return_error(gs_error_VMerror);
@@ -597,7 +597,7 @@
 	   "\033\052\162\103"
 	   "\033\045\0\130", 1, 9, prn_stream);
 
-    gs_free((char *)work, 3+sizeof(int), line_size, "alps_print_page(work)");
+    gs_free(pdev->memory, (char *)work, 3+sizeof(int), line_size, "alps_print_page(work)");
     return 0;
 }
 
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
