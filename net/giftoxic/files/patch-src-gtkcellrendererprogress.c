--- src/gtkcellrendererprogress.c.orig	Thu May 22 06:23:39 2003
+++ src/gtkcellrendererprogress.c	Sun Dec 28 14:28:27 2003
@@ -370,7 +370,13 @@
    */
   GdkGC *gc;
   gint draw_width; 
-      
+
+  PangoFontDescription *font;
+  
+  PangoContext *context;
+  PangoLayout *layout;
+  gchar *text;    
+  int w,h;
 
   if ((flags & GTK_CELL_RENDERER_SELECTED) == GTK_CELL_RENDERER_SELECTED)
     {
@@ -425,18 +431,17 @@
 
   
 
-  PangoFontDescription *font =  pango_font_description_from_string ("8");
+  font =  pango_font_description_from_string ("8");
   
-  PangoContext *context = gtk_widget_create_pango_context(widget);
-  PangoLayout *layout = pango_layout_new(context);
+  context = gtk_widget_create_pango_context(widget);
+  layout = pango_layout_new(context);
   
   pango_layout_set_font_description (layout, font);
-  gchar *text = g_strdup_printf("%.1f%%",cellprogress->priv->value);
+  text = g_strdup_printf("%.1f%%",cellprogress->priv->value);
   pango_layout_set_text(layout, text, -1);
   
   gdk_gc_set_rgb_fg_color (gc, &cellprogress->priv->text_color);
   
-  int w,h;
   pango_layout_get_pixel_size(layout, &w, &h);
   w = (cell_area->width - w)/2;
   h = (cell_area->height - h)/2;
