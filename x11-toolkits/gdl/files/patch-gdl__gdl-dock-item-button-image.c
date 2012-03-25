--- ./gdl/gdl-dock-item-button-image.c.orig	2012-03-19 01:16:15.000000000 +1030
+++ ./gdl/gdl-dock-item-button-image.c	2012-03-19 01:16:32.000000000 +1030
@@ -49,7 +49,7 @@
     cairo_set_line_width(cr, 1.0);
     
     style = gtk_widget_get_style (widget);
-    g_return_if_fail (style != NULL);
+    g_return_val_if_fail (style != NULL, 0);
     color = &style->fg[GTK_STATE_NORMAL];
     cairo_set_source_rgba(cr, color->red / 65535.0,
         color->green / 65535.0, color->blue / 65535.0, 0.55);
