--- src/gnome2/note_toolbar_style.c.orig	Thu Apr 22 14:12:43 2004
+++ src/gnome2/note_toolbar_style.c	Mon Feb 14 15:20:54 2005
@@ -469,11 +469,12 @@
 			    DIALOG_DATA * d)
 {
 	GSHTMLEditorControlData *cd = d->editor;
 	color_combo_set_color(COLOR_COMBO(cd->combo),
 			      &html_colorset_get_color_allocated
-			      (html->engine->painter,
+			      (cd->html->engine->settings->color_set,
+			       html->engine->painter,
 			       HTMLTextColor)->color);
 
 }
 
 /******************************************************************************
