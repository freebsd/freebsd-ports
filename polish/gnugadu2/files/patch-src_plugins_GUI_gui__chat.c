
$FreeBSD$

--- src/plugins/GUI/gui_chat.c.orig
+++ src/plugins/GUI/gui_chat.c
@@ -851,6 +851,7 @@
 	gint percent = 0;
 	gint number_of_workspaces = 0;
 	GtkWidget *chat_notebook_paned_size = NULL;
+	PangoFontDescription *font_desc;
 
 	if (!session || !plugin_name || !id)
 		return NULL;
@@ -1117,7 +1118,6 @@
 
     /* set font of the message editing text_view */
 
-    PangoFontDescription *font_desc;
     fontstr = ggadu_config_var_get(gui_handler, "msg_out_edit_font");
     font_desc = pango_font_description_from_string (fontstr);
     gtk_widget_modify_font (input, font_desc);
