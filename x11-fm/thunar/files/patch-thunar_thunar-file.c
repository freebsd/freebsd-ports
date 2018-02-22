--- thunar/thunar-file.c.orig	2017-11-25 16:54:56 UTC
+++ thunar/thunar-file.c
@@ -3966,7 +3966,9 @@ thunar_file_unwatch (ThunarFile *file)
 gboolean
 thunar_file_reload (ThunarFile *file)
 {
-  _thunar_return_val_if_fail (THUNAR_IS_FILE (file), FALSE);
+  /* if the file has already been destroyed, break here */
+  if (!THUNAR_IS_FILE (file))
+      return FALSE;
 
   /* clear file pxmap cache */
   thunar_icon_factory_clear_pixmap_cache (file);
@@ -4090,11 +4092,11 @@ thunar_file_compare_by_name (const ThunarFile *file_a,
 
   /* case insensitive checking */
   if (G_LIKELY (!case_sensitive))
-    result = strcmp (file_a->collate_key_nocase, file_b->collate_key_nocase);
+    result = g_strcmp0 (file_a->collate_key_nocase, file_b->collate_key_nocase);
 
   /* fall-back to case sensitive */
   if (result == 0)
-    result = strcmp (file_a->collate_key, file_b->collate_key);
+    result = g_strcmp0 (file_a->collate_key, file_b->collate_key);
 
   /* this happens in the trash */
   if (result == 0)
