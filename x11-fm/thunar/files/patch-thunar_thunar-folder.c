Avoid an infinite loop, during manual reload (bug #11849)

--- thunar/thunar-folder.c.orig	2015-04-18 14:25:18 UTC
+++ thunar/thunar-folder.c
@@ -551,10 +551,10 @@ thunar_folder_finished (ExoJob       *jo
   if (folder->reload_info)
     {
       for (lp = folder->files; lp != NULL; lp = lp->next)
-        thunar_file_reload_idle (lp->data);
+        thunar_file_reload (lp->data);
 
       /* reload folder information too */
-      thunar_file_reload_idle (folder->corresponding_file);
+      thunar_file_reload (folder->corresponding_file);
 
       folder->reload_info = FALSE;
     }
