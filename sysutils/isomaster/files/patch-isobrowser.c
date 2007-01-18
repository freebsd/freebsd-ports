--- isobrowser.c.orig	Sun Jan  7 14:11:34 2007
+++ isobrowser.c	Wed Jan 17 14:31:16 2007
@@ -57,6 +57,7 @@
 void addToIsoCbk(GtkButton *button, gpointer data)
 {
     GtkTreeSelection* selection;
+    char sizeStr[20];
     
     if(!GBLisoPaneActive)
     /* no iso open */
@@ -73,7 +74,6 @@
     }
     
     /* iso size label */
-    char sizeStr[20];
     GBLisoSize = 35845;
     //if(GBLvolInfo.filenameTypes & FNTYPE_JOLIET)
         GBLisoSize += 2048;
@@ -354,6 +354,7 @@
 void deleteFromIsoCbk(GtkButton *button, gpointer data)
 {
     GtkTreeSelection* selection;
+    char sizeStr[20];
     
     if(!GBLisoPaneActive)
     /* no iso open */
@@ -370,7 +371,6 @@
     }
     
     /* iso size label */
-    char sizeStr[20];
     GBLisoSize = 35845;
     //if(GBLvolInfo.filenameTypes & FNTYPE_JOLIET)
         GBLisoSize += 2048;
@@ -712,6 +712,7 @@
 {
     int rc;
     GtkWidget* warningDialog;
+    char sizeStr[20];
     
     if(GBLisoChangesProbable && !confirmCloseIso())
         return TRUE;
@@ -738,7 +739,6 @@
     GBLappSettings.filenameTypesToWrite = FNTYPE_9660 | FNTYPE_ROCKRIDGE | FNTYPE_JOLIET;
     
     /* iso size label */
-    char sizeStr[20];
     GBLisoSize = 35845;
     //if(GBLvolInfo.filenameTypes & FNTYPE_JOLIET)
         GBLisoSize += 2048;
@@ -763,6 +763,7 @@
 {
     int rc;
     GtkWidget* warningDialog;
+    char sizeStr[20];
     
     closeIso();
     
@@ -840,7 +841,6 @@
     /* END READ entire directory tree */
     
     /* iso size label */
-    char sizeStr[20];
     GBLisoSize = 35845;
     //if(GBLvolInfo.filenameTypes & FNTYPE_JOLIET)
         GBLisoSize += 2048;
@@ -896,10 +896,11 @@
     
     if(dialogRespose == GTK_RESPONSE_ACCEPT)
     {
+        char* lastIsoDir;
         filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
         
         /* RECORD last iso dir */
-        char* lastIsoDir = gtk_file_chooser_get_current_folder(GTK_FILE_CHOOSER(dialog));
+        lastIsoDir = gtk_file_chooser_get_current_folder(GTK_FILE_CHOOSER(dialog));
         
         if(GBLappSettings.lastIsoDir != NULL && strlen(lastIsoDir) > strlen(GBLappSettings.lastIsoDir))
         {
@@ -955,6 +956,7 @@
 void refreshIsoView(void)
 {
     char* isoCurrentDir; /* for changeIsoDirectory() */
+    GdkRectangle visibleRect;
     
     isoCurrentDir = malloc(strlen(GBLisoCurrentDir) + 1);
     if(isoCurrentDir == NULL)
@@ -963,7 +965,6 @@
     strcpy(isoCurrentDir, GBLisoCurrentDir);
     
     /* remember scroll position */
-    GdkRectangle visibleRect;
     gtk_tree_view_get_visible_rect(GTK_TREE_VIEW(GBLisoTreeView), &visibleRect);
     
     changeIsoDirectory(isoCurrentDir);
@@ -1083,10 +1084,11 @@
     
     if(dialogResponse == GTK_RESPONSE_ACCEPT)
     {
+        char* lastIsoDir;
         filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
         
         /* RECORD last iso dir */
-        char* lastIsoDir = gtk_file_chooser_get_current_folder(GTK_FILE_CHOOSER(dialog));
+        lastIsoDir = gtk_file_chooser_get_current_folder(GTK_FILE_CHOOSER(dialog));
         
         if(GBLappSettings.lastIsoDir != NULL && strlen(lastIsoDir) > strlen(GBLappSettings.lastIsoDir))
         {
