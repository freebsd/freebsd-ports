--- src/plugin.c.orig	Wed May 10 12:13:52 2006
+++ src/plugin.c	Wed May 10 12:22:47 2006
@@ -28,10 +28,11 @@
 
 static void save_all_caches(FolderItem *item, gpointer data)
 {
+	gchar *id;
 	
 	if (!item->cache)
 		return;
-	gchar *id = folder_item_get_identifier(item);
+	id = folder_item_get_identifier(item);
 	g_free(id);
 	folder_item_write_cache(item);
 }
