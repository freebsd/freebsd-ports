--- Input/mpg123/fileinfo.c.orig	Sat Feb  7 18:24:23 2004
+++ Input/mpg123/fileinfo.c	Sat Feb  7 18:34:26 2004
@@ -299,6 +299,13 @@
 {
     gint i;
     gchar *title;
+	GtkWidget *pixmapwid;
+	GdkPixbuf *pixbuf;
+	PangoAttribute *attr;
+	PangoAttrList *attrs;
+	GtkWidget *test_table;
+	GtkWidget *urk, *blark;
+	struct stat mstat;
 
     emphasis[0] = _("None");
     emphasis[1] = _("50/15 ms");
@@ -323,8 +330,6 @@
 	filename_vbox = gtk_hbox_new(FALSE, 5);
 	gtk_box_pack_start(GTK_BOX(vbox), filename_vbox, FALSE, TRUE, 0);
 
-	GtkWidget *pixmapwid;
-	GdkPixbuf *pixbuf;
 	pixbuf = gdk_pixbuf_new_from_xpm_data((const char **)
 					      gnome_mime_audio_xpm);
 	pixmapwid = gtk_image_new_from_pixbuf(pixbuf);
@@ -335,9 +340,6 @@
 
 	label = gtk_label_new(NULL);
 
-	PangoAttrList *attrs;
-	PangoAttribute *attr;
-
 	attrs = pango_attr_list_new();
 
 	attr = pango_attr_weight_new(PANGO_WEIGHT_BOLD);
@@ -382,7 +384,7 @@
 	//// MPEG Layer Info
 
 	// FIXME: Obvious...
-	GtkWidget *test_table = gtk_table_new(2, 10, FALSE);
+	test_table = gtk_table_new(2, 10, FALSE);
 	gtk_container_set_border_width(GTK_CONTAINER(test_table), 0);
 	gtk_container_add(GTK_CONTAINER(mpeg_box), test_table);
 
@@ -457,8 +459,6 @@
 	gtk_table_attach(GTK_TABLE(test_table), mpeg_filesize_val, 1, 2, 4,
 			 5, GTK_FILL, GTK_FILL, 10, 2);
 
-	GtkWidget *urk, *blark;
-
 	urk = gtk_label_new("");
 	blark = gtk_label_new("");
 	gtk_misc_set_alignment(GTK_MISC(urk), 1, 0.5);
@@ -756,7 +756,6 @@
 	return;
     }
 
-    struct stat mstat;
     stat(filename, &mstat);
     gtk_widget_set_sensitive(id3_frame,
 			     ((mstat.st_mode & S_IWRITE) == S_IWRITE));
