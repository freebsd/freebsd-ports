--- src/feed.c.orig	Thu Oct  5 15:55:26 2006
+++ src/feed.c	Thu Oct  5 15:55:51 2006
@@ -1377,9 +1377,9 @@
 	FolderItem *new_item;
 	RSSylFolderItem *ritem;
 	gchar *myurl = NULL;
+	gchar *error = NULL;	
 	g_return_val_if_fail(parent != NULL, FALSE);
 	g_return_val_if_fail(url != NULL, FALSE);
-	gchar *error = NULL;
 
 	myurl = g_strdup(url);
 
