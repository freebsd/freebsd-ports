--- engines/clearlooks/src/clearlooks_draw.c-	Sat Mar 11 21:18:32 2006
+++ engines/clearlooks/src/clearlooks_draw.c	Thu Mar 16 11:29:03 2006
@@ -725,13 +725,14 @@
 	gboolean has_focus = widget && GTK_WIDGET_HAS_FOCUS (widget);
 	
 	int cl, cr;
-	
+	GdkGC *bg_gc;
+
 	rtl = cl_get_parent_direction (widget) == GTK_TEXT_DIR_RTL;
 	
 	cl = rtl ? CL_CORNER_NONE  : CL_CORNER_ROUND;
 	cr = rtl ? CL_CORNER_ROUND : CL_CORNER_NONE;
 	
-	GdkGC *bg_gc = cl_get_window_bg_gc(widget, style);
+	bg_gc = cl_get_window_bg_gc(widget, style);
 	
 	if (rtl)
 	{
