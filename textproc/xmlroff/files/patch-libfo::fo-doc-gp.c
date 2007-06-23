--- libfo/fo-doc-gp.c.orig	Sun Jul 23 05:13:09 2006
+++ libfo/fo-doc-gp.c	Sat Aug 19 01:26:49 2006
@@ -1237,6 +1237,7 @@
 			gint               y)
 {
   PangoLayoutIter *iter;
+  gint line_number = -1;
   
   g_return_if_fail (context != NULL);
   g_return_if_fail (PANGO_IS_LAYOUT (layout));
@@ -1245,7 +1246,6 @@
 
   iter = pango_layout_get_iter (layout);
 
-  gint line_number = -1;
   do
     {
       PangoRectangle   logical_rect;
@@ -1296,6 +1296,9 @@
 			       gdouble   x,
 			       gdouble   y)
 {
+  gdouble x1, x2, y1, y2;
+  guint line_first, line_last;
+
   g_return_if_fail (FO_IS_DOC_GP (fo_doc));
   g_return_if_fail (FO_DOC_GP (fo_doc)->context != NULL);
   g_return_if_fail (FO_IS_AREA_LAYOUT (area_layout));
@@ -1307,9 +1310,9 @@
    * lines that are to be rendered.
    */
 
-  gdouble y1 = y;
+  y1 = y;
 
-  guint line_first = fo_area_layout_get_line_first (area_layout);
+  line_first = fo_area_layout_get_line_first (area_layout);
   if (line_first > 0)
     {
       y1 =
@@ -1317,12 +1320,12 @@
 					    line_first - 1);
     }
 
-  guint line_last = fo_area_layout_get_line_last (area_layout);
-  gdouble y2 =
+  line_last = fo_area_layout_get_line_last (area_layout);
+  y2 =
       y1 - fo_area_layout_get_line_height (area_layout,
 					   line_last);
 
-  gdouble x2 =
+  x2 =
       x + fo_area_area_get_width (area_layout);
 
 #if ENABLE_CLIP
