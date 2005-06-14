--- libfo/fo-doc-gp.c.orig	Thu Mar 31 16:36:10 2005
+++ libfo/fo-doc-gp.c	Tue Jun 14 21:11:30 2005
@@ -1143,6 +1143,7 @@
 			gint              y)
 {
   PangoLayoutIter *iter;
+  gint line_number = -1;
   
   g_return_if_fail (context != NULL);
   g_return_if_fail (PANGO_IS_LAYOUT (layout));
@@ -1152,7 +1153,6 @@
 
   iter = pango_layout_get_iter (layout);
 
-  gint line_number = -1;
   do
     {
       PangoRectangle   logical_rect;
@@ -1202,6 +1202,9 @@
 			       gfloat   x,
 			       gfloat   y)
 {
+  gfloat x1, x2, y1, y2;
+  gint line_first, line_last;
+
   g_return_if_fail (FO_IS_DOC_GP (fo_doc));
   g_return_if_fail (FO_DOC_GP (fo_doc)->context != NULL);
   g_return_if_fail (FO_IS_AREA_LAYOUT (area_layout));
@@ -1213,9 +1216,9 @@
    * lines that are to be rendered.
    */
 
-  gfloat y1 = y;
+  y1 = y;
 
-  gint line_first = fo_area_layout_get_line_first (area_layout);
+  line_first = fo_area_layout_get_line_first (area_layout);
   if (line_first > 0)
     {
       y1 =
@@ -1223,12 +1226,12 @@
 					    line_first - 1);
     }
 
-  gint line_last = fo_area_layout_get_line_last (area_layout);
-  gfloat y2 =
+  line_last = fo_area_layout_get_line_last (area_layout);
+  y2 =
       y1 - fo_area_layout_get_line_height (area_layout,
 					   line_last);
 
-  gfloat x2 =
+  x2 =
       x + fo_area_area_get_width (area_layout);
 
   gnome_print_gsave (FO_DOC_GP(fo_doc)->context);
