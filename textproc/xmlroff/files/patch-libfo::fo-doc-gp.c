--- libfo/fo-doc-gp.c.orig	Mon Jan 10 13:49:31 2005
+++ libfo/fo-doc-gp.c	Mon Jan 10 13:50:19 2005
@@ -1065,6 +1065,9 @@
 			       gfloat   x,
 			       gfloat   y)
 {
+  gfloat x1, x2, y1, y2;
+  gint line_first, line_last;
+
   g_return_if_fail (FO_IS_DOC_GP (fo_doc));
   g_return_if_fail (FO_DOC_GP (fo_doc)->context != NULL);
   g_return_if_fail (FO_IS_AREA_LAYOUT (area_layout));
@@ -1076,9 +1079,9 @@
    * lines that are to be rendered.
    */
 
-  gfloat y1 = y;
+  y1 = y;
 
-  gint line_first = fo_area_layout_get_line_first (area_layout);
+  line_first = fo_area_layout_get_line_first (area_layout);
   if (line_first > 0)
     {
       y1 =
@@ -1086,12 +1089,12 @@
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
