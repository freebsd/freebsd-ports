--- engines/crux/src/crux-draw.c.orig	Wed Aug 24 12:45:47 2005
+++ engines/crux/src/crux-draw.c	Wed Aug 24 12:46:08 2005
@@ -2323,6 +2323,8 @@ draw_extension (GtkStyle *style,
     GdkRectangle rect;
 
     eazel_theme_data *theme_data;
+    GtkWidget* parent_widget;
+    gint relative_x;
 
     g_return_if_fail (style != NULL);
     g_return_if_fail (window != NULL);
@@ -2334,8 +2336,6 @@ draw_extension (GtkStyle *style,
 	    detail, state_type, shadow_type, x, y, width, height);
 
 	/* Get x relative to parent widget, not window */
-	GtkWidget* parent_widget;
-	gint relative_x;
 	if (widget != NULL)
 	{
 		parent_widget = gtk_widget_get_parent(widget);
