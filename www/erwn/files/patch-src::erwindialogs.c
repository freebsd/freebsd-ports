--- src/erwindialogs.c.orig	Sun Jul 11 17:39:47 2004
+++ src/erwindialogs.c	Sun Jul 11 17:40:13 2004
@@ -125,9 +125,9 @@
 {
 	GtkWidget *dialog;
 	GtkFileFilter *filter_all = gtk_file_filter_new ();
+	GtkFileFilter *filter_html = gtk_file_filter_new ();
 	gtk_file_filter_add_pattern (filter_all, "*");
 	gtk_file_filter_set_name(filter_all,"All Files");
-	GtkFileFilter *filter_html = gtk_file_filter_new ();
 	gtk_file_filter_add_pattern (filter_html, "*html");
 	gtk_file_filter_set_name(filter_html,"HTML Files");
 
