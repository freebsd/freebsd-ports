--- Input/vorbis/fileinfo.c.orig	Sat Jul 31 22:46:58 2004
+++ Input/vorbis/fileinfo.c	Sat Jul 31 22:52:22 2004
@@ -200,7 +200,7 @@
     gchar *errorstring;
     errorstring = g_strdup_printf(_("An error occured:\n%s"), error);
 
-    xmms_show_message_test(_("Error!"),
+    xmms_show_message(_("Error!"),
 			   errorstring, _("Ok"), FALSE, NULL, NULL);
 
     g_free(errorstring);
@@ -488,12 +488,21 @@
 
     static GtkWidget *filename_entry, *tag_frame;
 
+	GtkWidget *hbox, *label, *filename_hbox, *vbox, *left_vbox;
+	GtkWidget *table, *bbox, *cancel_button;
+	GtkWidget *pixmapwid;
+	GdkPixbuf *pixbuf; 
+	PangoAttrList *attrs;
+	PangoAttribute *attr;
+	GtkWidget *boxx;
+	GtkImage *img;
+	GtkWidget *test_table;
+	struct stat mstat;
+
     g_free(vte.filename);
     vte.filename = g_strdup(fn);
 
     if (!window) {
-	GtkWidget *hbox, *label, *filename_hbox, *vbox, *left_vbox;
-	GtkWidget *table, *bbox, *cancel_button;
 
 	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
 	gtk_window_set_policy(GTK_WINDOW(window), FALSE, FALSE, FALSE);
@@ -508,17 +517,13 @@
 	filename_hbox = gtk_hbox_new(FALSE, 5);
 	gtk_box_pack_start(GTK_BOX(vbox), filename_hbox, FALSE, TRUE, 0);
 
-	GtkWidget *pixmapwid;
-	GdkPixbuf *pixbuf = gdk_pixbuf_new_from_xpm_data((const char **)
+	pixbuf = gdk_pixbuf_new_from_xpm_data((const char **)
 							 gnome_mime_audio_ogg_xpm);
 	pixmapwid = gtk_image_new_from_pixbuf(pixbuf);
 	gtk_misc_set_alignment(GTK_MISC(pixmapwid), 0, 0);
 	gtk_box_pack_start(GTK_BOX(filename_hbox), pixmapwid, FALSE, FALSE,
 			   0);
 
-	PangoAttrList *attrs;
-	PangoAttribute *attr;
-
 	attrs = pango_attr_list_new();
 
 	attr = pango_attr_weight_new(PANGO_WEIGHT_BOLD);
@@ -722,7 +727,6 @@
 			 GTK_FILL | GTK_EXPAND | GTK_SHRINK, 0, 5);
 #endif
 
-	GtkWidget *boxx;
 	boxx = gtk_hbutton_box_new();
 	gtk_hbutton_box_set_layout_default(GTK_BUTTONBOX_SPREAD);
 
@@ -739,7 +743,7 @@
 	gtk_table_attach(table, boxx, 0, 5, 6, 7, GTK_FILL, 0, 0, 8);
 
 	rg_show_button = gtk_toggle_button_new();
-	GtkImage *img = gtk_image_new_from_stock(GTK_STOCK_GO_FORWARD,
+	img = gtk_image_new_from_stock(GTK_STOCK_GO_FORWARD,
 						 GTK_ICON_SIZE_MENU);
 	gtk_container_add(rg_show_button, img);
 	g_signal_connect(G_OBJECT(rg_show_button), "toggled",
@@ -832,7 +836,7 @@
 	gtk_box_set_spacing(GTK_BOX(info_box), 0);
 
 	// FIXME: Obvious...
-	GtkWidget *test_table = gtk_table_new(2, 10, FALSE);
+	test_table = gtk_table_new(2, 10, FALSE);
 	gtk_container_set_border_width(GTK_CONTAINER(test_table), 0);
 	gtk_container_add(GTK_CONTAINER(info_box), test_table);
 
@@ -1073,7 +1077,6 @@
     gtk_window_set_title(GTK_WINDOW(window), tmp);
 //      rg_show_cb(rg_show_button, NULL);
 
-    struct stat mstat;
     stat(fn, &mstat);
     gtk_widget_set_sensitive(tag_frame,
 			     ((mstat.st_mode & S_IWRITE) == S_IWRITE));
