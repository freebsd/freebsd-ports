--- src/erwindialogs.c.orig	Thu Jan 20 05:59:44 2005
+++ src/erwindialogs.c	Thu Mar 31 18:52:42 2005
@@ -125,9 +125,9 @@
 {
 	GtkWidget *dialog;
 	GtkFileFilter *filter_all = gtk_file_filter_new();
+	GtkFileFilter *filter_html = gtk_file_filter_new();
 	gtk_file_filter_add_pattern(filter_all, "*");
 	gtk_file_filter_set_name(filter_all, "All Files");
-	GtkFileFilter *filter_html = gtk_file_filter_new();
 	gtk_file_filter_add_pattern(filter_html, "*html");
 	gtk_file_filter_set_name(filter_html, "HTML Files");
 
