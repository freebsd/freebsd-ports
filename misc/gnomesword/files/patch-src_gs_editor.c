--- src/gs_editor.c	2003/01/12 00:35:43	1.7
+++ src/gs_editor.c	2003/01/13 16:53:17	1.8
@@ -52,7 +52,7 @@
 #include <gtkhtml/htmlcolor.h>
 #include <gtkhtml/htmlcolorset.h>
 #include <gtkhtml/htmllinktext.h>
-#endif		
+#endif
 
 #ifdef USE_SPELL
 #include "spell.h"
@@ -392,7 +392,6 @@
 		g_warning("file not writen");
 	else
 		g_warning("file writen");
-	//g_warning(gstr->str);
 
 	gtk_text_insert(GTK_TEXT(text), NULL,
 			&text->style->black, NULL, gstr->str, -1);
@@ -428,7 +427,6 @@
 		 GSHTMLEditorControlData * ecd)
 {
 	ecd->changed = TRUE;
-	//file_changed = TRUE;
 	updatestatusbar(ecd);
 	return 1;
 }
@@ -511,7 +509,7 @@
 GtkWidget *create_editor(GtkWidget * htmlwidget, GtkWidget * vbox,
 			 SETTINGS * s, GSHTMLEditorControlData * necd)
 {
-	GtkWidget * frame34, *scrolledwindow17;
+	GtkWidget *frame34, *scrolledwindow17;
 
 	frame34 = gtk_frame_new(NULL);
 	gtk_widget_ref(frame34);
@@ -1251,22 +1249,25 @@
 set_link_to_module(gchar * linkref, gchar * linkmod,
 		   GSHTMLEditorControlData * ecd)
 {
-	gchar buf[256], *target = "";
+	const gchar *url;
+	const gchar *text;
+	gchar *target;
+	gchar *url_copy;
+	gchar buf[256];
+	HTMLEngine *e;
+	HTMLObject *new_link;
+
+	e = ecd->html->engine;
 	
-	HTMLEngine *e = ecd->html->engine;	
 	if (strlen(linkmod))
 		sprintf(buf, "version=%s passage=%s", linkmod, linkref);
 	else
 		sprintf(buf, "passage=%s", linkref);
-	
+
 #ifdef USE_GTKHTML1
-	const gchar *url;
-	const gchar *text;
 	url = buf;
 	text = linkref;
 	if (url && text && *url && *text) {
-		HTMLObject *new_link;
-		gchar *url_copy;
 		target = strchr(url, '#');
 		url_copy =
 		    target ? g_strndup(url,
@@ -1274,14 +1275,17 @@
 		new_link =
 		    html_link_text_new(text,
 				       GTK_HTML_FONT_STYLE_DEFAULT,
-				       html_colorset_get_color(e->settings->color_set,
-							       HTMLLinkColor),
+				       html_colorset_get_color(e->
+							settings->
+							color_set,
+							HTMLLinkColor),
 				       url_copy, target);
 		html_engine_paste_object(e, new_link,
 					 g_utf8_strlen(text, -1));
 		g_free(url_copy);
 	}
 #else
+	target = "";
 	html_engine_selection_push(e);
 	html_engine_insert_link(e, buf, target);
 	html_engine_selection_pop(e);
