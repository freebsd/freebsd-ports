--- beep/prefswin.c.orig	Fri Nov 14 05:33:05 2003
+++ beep/prefswin.c	Fri Nov 14 05:36:04 2003
@@ -752,11 +752,15 @@
 	GtkObject *options_mouse_adj;
 	GtkWidget *prefswin_title_desc, *prefswin_title_label, *opt;
 
+	GtkWidget *table_rb;
+	GtkWidget *label;
+
 	char *titles[1];
 
 	PangoAttrList *attrs;
 	PangoAttribute *attr;
 
+	PangoFontDescription * playlist_list_font;
 
 	prefswin = gtk_window_new(GTK_WINDOW_TOPLEVEL);
 	gtk_window_set_position(GTK_WINDOW(prefswin),GTK_WIN_POS_CENTER);
@@ -1019,7 +1023,6 @@
 	gtk_container_add(GTK_CONTAINER(prefswin_options_frame), options_table);
 	gtk_container_border_width(GTK_CONTAINER(options_table), 5);
 
-	GtkWidget * table_rb;
 	table_rb = gtk_table_new(4,4,FALSE);
 
 	options_gi_box = gtk_hbox_new(FALSE, 3);
@@ -1110,7 +1113,6 @@
 	prefswin_fonts_vbox = gtk_table_new(4,4,TRUE);
 
 	// This ain't exactly GnomeFontPicker, but we're not a GNOME app so no GNOME widgets for us	
-	GtkWidget *label;
 	label = gtk_label_new("Playlist Font:");
 
 	attrs = pango_attr_list_new ();
@@ -1126,7 +1128,7 @@
 
 	prefswin_options_font_browse = gtk_button_new();
 	label_font = gtk_label_new(cfg.playlist_font);
-	PangoFontDescription * playlist_list_font = pango_font_description_from_string (cfg.playlist_font);
+	playlist_list_font = pango_font_description_from_string (cfg.playlist_font);
 	gtk_widget_modify_font(label_font, playlist_list_font);
 	gtk_container_add(GTK_CONTAINER(prefswin_options_font_browse), label_font);
 
