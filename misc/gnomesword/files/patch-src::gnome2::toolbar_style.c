--- src/gnome2/toolbar_style.c.orig	Thu Apr 22 14:12:43 2004
+++ src/gnome2/toolbar_style.c	Mon Feb 14 15:23:28 2005
@@ -460,11 +460,12 @@
 static void set_color_combo(GtkHTML * html,
 			    GSHTMLEditorControlData * cd)
 {
 	color_combo_set_color(COLOR_COMBO(cd->combo),
 			      &html_colorset_get_color_allocated
-			      (html->engine->painter,
+			      (cd->html->engine->settings->color_set,
+			       html->engine->painter,
 			       HTMLTextColor)->color);
 
 }
 
 /******************************************************************************
