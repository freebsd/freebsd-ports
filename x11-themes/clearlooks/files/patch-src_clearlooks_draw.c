--- src/clearlooks_draw.c.orig	Thu Feb 24 09:15:18 2005
+++ src/clearlooks_draw.c	Sun Feb 27 01:51:30 2005
@@ -57,16 +57,16 @@
                 int x, int y, int width, int height,
                 GdkColor *left_color, GdkColor *right_color)
 {
-	if ( left_color == NULL || right_color == NULL )
-	{
-		gdk_draw_rectangle (drawable, gc, TRUE, x, y, width, height);
-		return;
-	}
 
 	int i;
 	GdkColor col;
 	int dr, dg, db;
 	GdkGCValues old_values;
+	if ( left_color == NULL || right_color == NULL )
+	{
+		gdk_draw_rectangle (drawable, gc, TRUE, x, y, width, height);
+		return;
+	}
 
 	gdk_gc_get_values (gc, &old_values);
 	
@@ -179,10 +179,10 @@
 void cl_draw_borders (GdkWindow *window, GtkWidget *widget, GtkStyle *style,
                       int x, int y, int width, int height, CLRectangle *r)
 {
+	int x1, y1, x2, y2, i;
 	if (r->bordergc == NULL)
 		return;
 
-	int x1, y1, x2, y2, i;
 	for ( i=0; i<4; i++) // draw all four borders + corners
 	{
 		cl_get_coords (i, x, y, width, height, r, &x1, &y1, &x2, &y2);
@@ -261,9 +261,6 @@
                      int x, int y, int width, int height,
                      CLRectangle *r, CLCornerSide corner)
 {
-	if (r->corners[corner] == CL_CORNER_NONE)
-		return;
-	
 	GdkColor    *color;
 	GdkColor     aacolor; // anti-aliasing color
 	GdkGCValues  values;
@@ -271,6 +268,9 @@
 	
 	int x1;
 	int y1;
+
+        if (r->corners[corner] == CL_CORNER_NONE)
+                return;
 
 	color = cl_get_gradient_corner_color (r, corner);
 	gdk_gc_get_values (r->bordergc, &values);
