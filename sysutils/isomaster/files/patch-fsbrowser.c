--- fsbrowser.c.orig	Thu Dec 28 05:44:19 2006
+++ fsbrowser.c	Wed Jan 17 14:27:07 2007
@@ -419,6 +419,7 @@
 void refreshFsView(void)
 {
     char* fsCurrentDir; /* for changeFsDirectory() */
+    GdkRectangle visibleRect;
     
     fsCurrentDir = malloc(strlen(GBLfsCurrentDir) + 1);
     if(fsCurrentDir == NULL)
@@ -426,7 +427,6 @@
     strcpy(fsCurrentDir, GBLfsCurrentDir);
     
     /* remember scroll position */
-    GdkRectangle visibleRect;
     gtk_tree_view_get_visible_rect(GTK_TREE_VIEW(GBLfsTreeView), &visibleRect);
     
     changeFsDirectory(fsCurrentDir);
