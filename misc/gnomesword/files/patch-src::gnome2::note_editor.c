--- src/gnome2/note_editor.c.orig	Thu May  6 19:10:00 2004
+++ src/gnome2/note_editor.c	Mon Feb 14 15:12:22 2005
@@ -29,11 +29,11 @@
 #include <gtkhtml/htmlform.h>
 #include <gtkhtml/htmlenums.h>
 #include <gtkhtml/htmlsettings.h>
 #include <gtkhtml/htmlcolor.h>
 #include <gtkhtml/htmlcolorset.h>
-#include <gtkhtml/htmllinktext.h>
+//#include <gtkhtml/htmllinktext.h>
 #include <gtkhtml/htmlengine-edit.h>
 #include <gtkhtml/htmlengine-edit-fontstyle.h>
 #include <gtkhtml/htmlengine-edit-cut-and-paste.h>
 #include <gtkhtml/htmlselection.h>
 #include <gtkhtml/htmlengine-search.h>
@@ -1185,17 +1185,33 @@
 		target = strchr(url, '#');
 		url_copy =
 		    target ? g_strndup(url,
 				       target - url) : g_strdup(url);
 		new_link =
+		    html_text_new(text,
+				       GTK_HTML_FONT_STYLE_DEFAULT,
+				       html_colorset_get_color(e->
+							settings->
+							color_set,
+							HTMLLinkColor));
+		new_link =
+		    html_object_set_link(new_link,
+				       html_colorset_get_color(e->
+							settings->
+							color_set,
+							HTMLLinkColor),
+				       url_copy, target);
+/*
+		new_link =
 		    html_link_text_new(text,
 				       GTK_HTML_FONT_STYLE_DEFAULT,
 				       html_colorset_get_color(e->
 							settings->
 							color_set,
 							HTMLLinkColor),
 				       url_copy, target);
+*/
 		html_engine_paste_object(e, new_link,
 					 g_utf8_strlen(text, -1));
 		g_free(url_copy);
 	}
 }
