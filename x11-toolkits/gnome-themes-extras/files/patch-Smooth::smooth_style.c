--- Smooth/smooth_style.c.orig	Thu Dec 11 10:05:56 2003
+++ Smooth/smooth_style.c	Thu Dec 11 10:06:13 2003
@@ -707,7 +707,7 @@
 {
   g_return_if_fail(sanitize_parameters(style, window, &width, &height));
 
-  if ((EDGE_LINE_STYLE(style,NULL) == SMOOTH_LINE_FLAT)  && DETAIL ("entry") && widget && (GTK_IS_SPIN_BUTTON (widget) || (widget->parent && GTK_IS_COMBO(widget->parent)))) 
+  if ((EDGE_LINE_STYLE(style,NULL) == SMOOTH_LINE_FLAT)  && DETAIL ("entry") && widget && (GTK_IS_SPIN_BUTTON (widget) || (widget->parent && GTK_IS_COMBO_BOX(widget->parent)))) 
   {
        gtk_paint_flat_box(style, window, widget->state, GTK_SHADOW_NONE, area, widget, "entry_bg", x, y, width, height);
 
