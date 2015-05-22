--- thunar/thunar-file.c.orig	2015-05-16 14:25:55 UTC
+++ thunar/thunar-file.c
@@ -3910,8 +3910,12 @@ thunar_file_unwatch (ThunarFile *file)
  *
  * You must be able to handle the case that @file is
  * destroyed during the reload call.
+ *
+ * Return value: FALSE because if used as a callback function for
+ * thunar_file_reload_idle it should be automatically removed from
+ * the list of event sources so it is not called again.
  **/
-void
+gboolean
 thunar_file_reload (ThunarFile *file)
 {
   _thunar_return_if_fail (THUNAR_IS_FILE (file));
@@ -3923,12 +3927,13 @@ thunar_file_reload (ThunarFile *file)
     {
       /* destroy the file if we cannot query any file information */
       thunar_file_destroy (file);
-      return;
+      return FALSE;
     }
 
   /* ... and tell others */
   thunar_file_changed (file);
-  
+ 
+  return FALSE;
 }
 
 
@@ -3952,27 +3957,6 @@ thunar_file_reload_idle (ThunarFile *fil
 
 
 /**
- * thunar_file_reload_idle_timeout:
- * @file    : a #ThunarFile instance.
- * @timeout : the timeout in ms after which the reload should happen
- *
- * Schedules a reload of the @file by calling thunar_file_reload in
- * idle after @timeout milliseconds have passed.
- *
- **/
-void
-thunar_file_reload_idle_timeout (ThunarFile *file,
-                                 guint timeout)
-{
-  _thunar_return_if_fail (THUNAR_IS_FILE (file));
-
-  g_timeout_add_full (G_PRIORITY_DEFAULT_IDLE, timeout,
-                      (GSourceFunc) thunar_file_reload, file, NULL);
-}
-
-
-
-/**
  * thunar_file_destroy:
  * @file : a #ThunarFile instance.
  *
