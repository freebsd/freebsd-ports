--- qt_theme_draw.c.orig	Mon May 31 01:16:28 2004
+++ qt_theme_draw.c	Mon May 31 03:19:50 2004
@@ -257,6 +256,9 @@
 	    gint          height)
 {
 
+GdkGC *gc1 = NULL;
+GdkGC *gc2 = NULL;
+
 if (!widget) return;
 
   sanitize_size(window, &width, &height);
@@ -300,8 +302,6 @@
   }
 
   return;
-  GdkGC *gc1 = NULL;
-  GdkGC *gc2 = NULL;
 
   g_return_if_fail(style != NULL);
   g_return_if_fail(window != NULL);
@@ -687,9 +687,6 @@
            GtkArrowType arrow_type,
            gint fill, gint x, gint y, gint width, gint height)
 {
-  if (DETAIL("hscrollbar") || DETAIL("vscrollbar"))
-    return;
-  /*printf("Arrow (%d,%d,%d,%d) Widget: %s  Detail: %s\n",x,y,width,height,gtk_widget_get_name(widget),detail);*/
   GdkGC              *gc1;
   GdkGC              *gc2;
   GdkGC              *gc3;
@@ -698,6 +695,10 @@
   gint                half_height;
   gint                ax, ay, aw, ah;
 
+  if (DETAIL("hscrollbar") || DETAIL("vscrollbar"))
+    return;
+  /*printf("Arrow (%d,%d,%d,%d) Widget: %s  Detail: %s\n",x,y,width,height,gtk_widget_get_name(widget),detail);*/
+
   g_return_if_fail(style != NULL);
   g_return_if_fail(window != NULL);
 
@@ -1095,7 +1096,10 @@
 	gint y,
 	gint width,
 	gint height)
-{
+{	
+	GdkGC *light_gc, *dark_gc;
+	GtkOrientation      orientation;
+
 	sanitize_size(window, &width, &height);
 	/*printf("Box (%d,%d,%d,%d) Widget: %s  Detail: %s\n",x,y,width,height,gtk_widget_get_name(widget),detail);*/
 	if (WIDGET("GtkHScrollbar") || WIDGET("GtkVScrollbar"))
@@ -1136,9 +1140,6 @@
 	
 	/*printf("Box (%d,%d,%d,%d) Widget: %s Detail: %s\n",x,y,width,height,gtk_widget_get_name(widget),detail);*/
 	
-	GdkGC *light_gc, *dark_gc;
-	GtkOrientation      orientation;
-	
 	g_return_if_fail(style != NULL);
 	g_return_if_fail(window != NULL);
 	
@@ -1716,12 +1717,12 @@
             gint height,
             GtkOrientation orientation)
 {
-  return;
   GdkPoint pointsh[7];
   GdkRegion *clipreg;
   GdkRectangle rec;
   int i, rect = FALSE, midlines = MARKS_SLASH;
   int modx, mody;
+  return;
 
 
   g_return_if_fail(style != NULL);
