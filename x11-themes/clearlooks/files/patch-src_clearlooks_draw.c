--- src/clearlooks_draw.c.orig	Wed Mar  2 17:41:35 2005
+++ src/clearlooks_draw.c	Thu Mar  3 20:20:39 2005
@@ -67,10 +67,11 @@
 void cl_draw_borders (GdkWindow *window, GtkWidget *widget, GtkStyle *style,
                       int x, int y, int width, int height, CLRectangle *r)
 {
+        int x1, y1, x2, y2, i;
+
 	if (r->bordergc == NULL)
 		return;
 
-	int x1, y1, x2, y2, i;
 	for ( i=0; i<4; i++) // draw all four borders + corners
 	{
 		cl_get_coords (i, x, y, width, height, r, &x1, &y1, &x2, &y2);
@@ -149,8 +150,6 @@
                      int x, int y, int width, int height,
                      CLRectangle *r, CLCornerSide corner)
 {
-	if (r->corners[corner] == CL_CORNER_NONE)
-		return;
 	
 	GdkColor    *color;
 	GdkColor     aacolor; // anti-aliasing color
@@ -160,6 +159,9 @@
 	int x1;
 	int y1;
 
+        if (r->corners[corner] == CL_CORNER_NONE)
+                return;
+
 	color = cl_get_gradient_corner_color (r, corner);
 	gdk_gc_get_values (r->bordergc, &values);
 	
@@ -477,7 +479,8 @@
 	int width = height;
 	int line = 0;
 	int center = width/2;
-	int xdir = 1;
+	int xdir = 1, trans;
+        double shift;
 
 	int stripe_width = height/2;
 	int topright = height + stripe_width;	
@@ -490,6 +493,7 @@
 	                                 width,
 	                                 height, -1);
 
+        GdkPoint points[4];
 	GdkColor tmp_color;
 	shade (&clearlooks_style->spot2, &tmp_color, 0.90);
 	
@@ -510,7 +514,6 @@
 	if (get_direction (widget) == GTK_TEXT_DIR_RTL)
 		offset = -offset;
 	
-	GdkPoint points[4];
 	if (is_horizontal)
 	{
 		points[0] = (GdkPoint){xdir*(topright - stripe_width - topright_div_2), 0};  // topleft
@@ -527,10 +530,10 @@
 	}
 						 
 	
-	double shift = (stripe_width*2)/(double)10;
+        shift = (stripe_width*2)/(double)10;
 	cl_progressbar_points_transform (points, 4, (offset*shift), is_horizontal);
 		
-	int trans = (width/2)-1-(stripe_width*2);
+        trans = (width/2)-1-(stripe_width*2);
 	cl_progressbar_points_transform (points, 4, trans, is_horizontal);
 	gdk_draw_polygon (tmp, clearlooks_style->spot2_gc, TRUE, points, 4);
 	cl_progressbar_points_transform (points, 4, -trans, is_horizontal);
