--- Input/mpg123/fileinfo.c.orig	Fri Nov 14 05:40:55 2003
+++ Input/mpg123/fileinfo.c	Fri Nov 14 05:44:47 2003
@@ -299,6 +299,8 @@
 	gint i;
 	gchar *title;
 
+	struct stat mstat;
+
 	emphasis[0] = _("None");
 	emphasis[1] = _("50/15 ms");
 	emphasis[2] = "";
@@ -308,6 +310,14 @@
 
 	if (!window)
 	{
+		GtkWidget * pixmapwid;
+		GdkPixbuf * pixbuf;
+
+		PangoAttrList *attrs;
+		PangoAttribute     *attr;
+
+		GtkWidget * test_table;
+		GtkWidget *urk,*blark;
 		
 		window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
 		gtk_window_set_policy(GTK_WINDOW(window), FALSE, FALSE, FALSE);
@@ -322,8 +332,6 @@
 		filename_vbox = gtk_hbox_new(FALSE, 5);
 		gtk_box_pack_start(GTK_BOX(vbox), filename_vbox, FALSE, TRUE, 0);
 
-		GtkWidget * pixmapwid;
-		GdkPixbuf * pixbuf;
 		pixbuf = gdk_pixbuf_new_from_xpm_data((const char **)gnome_mime_audio_xpm);
 		pixmapwid = gtk_image_new_from_pixbuf(pixbuf);
 		g_object_unref(pixbuf);
@@ -332,9 +340,6 @@
 
 		label = gtk_label_new(NULL);
 
-		PangoAttrList *attrs;
-		PangoAttribute     *attr;
-
 		attrs = pango_attr_list_new ();
 
 		attr = pango_attr_weight_new (PANGO_WEIGHT_BOLD);
@@ -377,7 +382,7 @@
 		//// MPEG Layer Info
 
 		// FIXME: Obvious...
-		GtkWidget * test_table = gtk_table_new(2, 10, FALSE);
+		test_table = gtk_table_new(2, 10, FALSE);
 		gtk_container_set_border_width(GTK_CONTAINER(test_table), 0);
 		gtk_container_add(GTK_CONTAINER(mpeg_box), test_table);
 
@@ -437,8 +442,6 @@
 		gtk_label_set_justify(GTK_LABEL(mpeg_filesize_val), GTK_JUSTIFY_LEFT );
 		gtk_table_attach(GTK_TABLE(test_table), mpeg_filesize_val, 1, 2, 4, 5, GTK_FILL, GTK_FILL, 10, 2);
 
-		GtkWidget *urk,*blark;
-
 		urk = gtk_label_new("");
 		blark = gtk_label_new("");		
 		gtk_misc_set_alignment(GTK_MISC(urk), 1, 0.5);
@@ -683,7 +686,6 @@
 		return;
 	}
 
-	struct stat mstat;
 	stat(filename,&mstat);
 	gtk_widget_set_sensitive(id3_frame, ((mstat.st_mode & S_IWRITE) == S_IWRITE ) );
 	/* FIXME: Check for UID/GID too? */
