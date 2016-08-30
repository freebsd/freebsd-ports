--- thunar/thunar-file.c.orig	2015-05-22 13:25:36 UTC
+++ thunar/thunar-file.c
@@ -795,13 +795,15 @@ thunar_file_monitor (GFileMonitor     *m
       if (event_type == G_FILE_MONITOR_EVENT_MOVED)
         {
           /* reload the target file if cached */
+          if (other_path == NULL)
+            return;
           other_file = thunar_file_cache_lookup (other_path);
           if (other_file)
               thunar_file_reload (other_file);
           else
               other_file = thunar_file_get (other_path, NULL);
 
-          if (!other_file)
+          if (other_file == NULL)
               return;
 
           /* notify the thumbnail cache that we can now also move the thumbnail */
@@ -3918,7 +3920,9 @@ thunar_file_unwatch (ThunarFile *file)
 gboolean
 thunar_file_reload (ThunarFile *file)
 {
-  _thunar_return_if_fail (THUNAR_IS_FILE (file));
+  /* if the file has already been destroyed, break here */
+  if (!THUNAR_IS_FILE (file))
+      return FALSE;
 
   /* clear file pxmap cache */
   thunar_icon_factory_clear_pixmap_cache (file);
