--- capplets/mouse/gnome-mouse-properties.c.orig	Sun May  5 01:04:48 2002
+++ capplets/mouse/gnome-mouse-properties.c	Sun May  5 01:05:10 2002
@@ -532,7 +532,7 @@
 	filename = gnome_program_locate_file (program, GNOME_FILE_DOMAIN_APP_PIXMAP, "mouse-cursor-white.png", TRUE, NULL);
 	pixbuf = gdk_pixbuf_new_from_file (filename, NULL);
 	g_free (filename);
-	font_path = gnome_program_locate_file (program, GNOME_FILE_DOMAIN_DATADIR, "gnome/cursor-fonts/cursor-white.pcf.gz", FALSE, NULL);
+	font_path = gnome_program_locate_file (program, GNOME_FILE_DOMAIN_DATADIR, "cursor-fonts/cursor-white.pcf.gz", FALSE, NULL);
 
 	gtk_list_store_append (GTK_LIST_STORE (model), &iter);
 	if (cursor_font && ! strcmp (cursor_font, font_path)) {
@@ -553,7 +553,7 @@
 	filename = gnome_program_locate_file (program, GNOME_FILE_DOMAIN_APP_PIXMAP, "mouse-cursor-normal-large.png", TRUE, NULL);
 	pixbuf = gdk_pixbuf_new_from_file (filename, NULL);
 	g_free (filename);
-	font_path = gnome_program_locate_file (program, GNOME_FILE_DOMAIN_DATADIR, "gnome/cursor-fonts/cursor-large.pcf.gz", FALSE, NULL);
+	font_path = gnome_program_locate_file (program, GNOME_FILE_DOMAIN_DATADIR, "cursor-fonts/cursor-large.pcf.gz", FALSE, NULL);
 
 	gtk_list_store_append (GTK_LIST_STORE (model), &iter);
 	if (cursor_font && ! strcmp (cursor_font, font_path)) {
@@ -574,7 +574,7 @@
 	filename = gnome_program_locate_file (program, GNOME_FILE_DOMAIN_APP_PIXMAP, "mouse-cursor-white-large.png", TRUE, NULL);
 	pixbuf = gdk_pixbuf_new_from_file (filename, NULL);
 	g_free (filename);
-	font_path = gnome_program_locate_file (program, GNOME_FILE_DOMAIN_DATADIR, "gnome/cursor-fonts/cursor-large-white.pcf.gz", FALSE, NULL);
+	font_path = gnome_program_locate_file (program, GNOME_FILE_DOMAIN_DATADIR, "cursor-fonts/cursor-large-white.pcf.gz", FALSE, NULL);
 
 	gtk_list_store_append (GTK_LIST_STORE (model), &iter);
 	if (cursor_font && ! strcmp (cursor_font, font_path)) {
