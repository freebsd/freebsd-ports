--- Input/vorbis/fileinfo.c.orig	Wed Dec 24 09:02:52 2003
+++ Input/vorbis/fileinfo.c	Wed Dec 24 09:07:28 2003
@@ -498,6 +498,8 @@
 
 	static GtkWidget *filename_entry, *tag_frame;
 
+	struct stat mstat;
+
 	g_free(vte.filename);
 	vte.filename = g_strdup(fn);
 	
@@ -505,6 +507,13 @@
 	{
 		GtkWidget *hbox, *label, *filename_hbox, *vbox, *left_vbox;
 		GtkWidget *table, *bbox, *cancel_button;
+		GtkWidget * pixmapwid;
+		GdkPixbuf * pixbuf;
+		PangoAttrList *attrs;
+		PangoAttribute     *attr;
+		GtkWidget * boxx;
+		GtkImage * img;
+		GtkWidget * test_table;
 
 		window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
 		gtk_window_set_policy(GTK_WINDOW(window), FALSE, FALSE, FALSE);
@@ -519,14 +528,11 @@
 		filename_hbox = gtk_hbox_new(FALSE, 5);
 		gtk_box_pack_start(GTK_BOX(vbox), filename_hbox, FALSE, TRUE, 0);
 
-		GtkWidget * pixmapwid;
-		GdkPixbuf * pixbuf = gdk_pixbuf_new_from_xpm_data((const char **)gnome_mime_audio_ogg_xpm);
+		pixbuf = gdk_pixbuf_new_from_xpm_data((const char **)gnome_mime_audio_ogg_xpm);
 		pixmapwid = gtk_image_new_from_pixbuf(pixbuf);
 		gtk_misc_set_alignment(GTK_MISC(pixmapwid), 0, 0);
 		gtk_box_pack_start(GTK_BOX(filename_hbox), pixmapwid, FALSE, FALSE, 0);
 
-		PangoAttrList *attrs;
-		PangoAttribute     *attr;
 
 		attrs = pango_attr_list_new ();
 
@@ -728,7 +734,6 @@
 				 GTK_FILL | GTK_EXPAND | GTK_SHRINK, 0, 5);
 #endif
 
-		GtkWidget * boxx;
 		boxx = gtk_hbutton_box_new();
 		gtk_hbutton_box_set_layout_default(GTK_BUTTONBOX_SPREAD);
 
@@ -746,7 +751,7 @@
 		gtk_table_attach(table,boxx,0,5,6,7,GTK_FILL,0,0,8);
 
 		rg_show_button = gtk_toggle_button_new();
-		GtkImage * img = gtk_image_new_from_stock(GTK_STOCK_GO_FORWARD, GTK_ICON_SIZE_MENU);
+		img = gtk_image_new_from_stock(GTK_STOCK_GO_FORWARD, GTK_ICON_SIZE_MENU);
 		gtk_container_add(rg_show_button,img);
 		g_signal_connect(G_OBJECT(rg_show_button), "toggled",
 				   G_CALLBACK(rg_show_cb), NULL);
@@ -836,7 +841,7 @@
 		gtk_box_set_spacing(GTK_BOX(info_box), 0);
 
 		// FIXME: Obvious...
-		GtkWidget * test_table = gtk_table_new(2, 10, FALSE);
+		test_table = gtk_table_new(2, 10, FALSE);
 		gtk_container_set_border_width(GTK_CONTAINER(test_table), 0);
 		gtk_container_add(GTK_CONTAINER(info_box), test_table);
 
@@ -1068,7 +1073,6 @@
 	gtk_window_set_title(GTK_WINDOW(window), tmp);
 //	rg_show_cb(rg_show_button, NULL);
 
-	struct stat mstat;
 	stat(fn,&mstat);
 	gtk_widget_set_sensitive(tag_frame, ((mstat.st_mode & S_IWRITE) == S_IWRITE ) );
 
