--- boot.c.orig	Thu Jan 11 16:42:31 2007
+++ boot.c	Wed Jan 17 14:35:49 2007
@@ -48,10 +48,11 @@
     
     if(gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT)
     {
+        char* lastBootRecordDir;
         filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
         
         /* RECORD last boot record dir */
-        char* lastBootRecordDir = gtk_file_chooser_get_current_folder(GTK_FILE_CHOOSER(dialog));
+        lastBootRecordDir = gtk_file_chooser_get_current_folder(GTK_FILE_CHOOSER(dialog));
         
         if(GBLappSettings.lastBootRecordDir != NULL && 
            strlen(lastBootRecordDir) > strlen(GBLappSettings.lastBootRecordDir))
@@ -162,10 +163,11 @@
     
     if(dialogResponse == GTK_RESPONSE_ACCEPT)
     {
+        char* lastBootRecordDir;
         filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
         
         /* RECORD last boot record dir */
-        char* lastBootRecordDir = gtk_file_chooser_get_current_folder(GTK_FILE_CHOOSER(dialog));
+        lastBootRecordDir = gtk_file_chooser_get_current_folder(GTK_FILE_CHOOSER(dialog));
         
         if(GBLappSettings.lastBootRecordDir != NULL && 
            strlen(lastBootRecordDir) > strlen(GBLappSettings.lastBootRecordDir))
