--- gfx/src/gtk/gtk2drawing.c.fixgtk212	2005-09-13 05:30:53.000000000 +0200
+++ gfx/src/gtk/gtk2drawing.c	2007-09-06 09:42:34.000000000 +0200
@@ -551,8 +551,8 @@ moz_gtk_option_menu_get_metrics(gboolean
     else
         *indicator_spacing = default_indicator_spacing;
 
-    g_free(tmp_indicator_size);
-    g_free(tmp_indicator_spacing);
+    gtk_requisition_free(tmp_indicator_size);
+    gtk_border_free(tmp_indicator_spacing);
  
     return MOZ_GTK_SUCCESS;
 }
