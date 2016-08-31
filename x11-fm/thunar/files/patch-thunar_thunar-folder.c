--- thunar/thunar-folder.c.orig	2015-05-22 13:25:36 UTC
+++ thunar/thunar-folder.c
@@ -773,27 +773,30 @@ thunar_folder_monitor (GFileMonitor     
             {
               /* destroy the old file and update the new one */
               thunar_file_destroy (lp->data);
-              file = thunar_file_get(other_file, NULL);
-              if (file != NULL && THUNAR_IS_FILE (file))
+              if (other_file != NULL)
                 {
-                  thunar_file_reload (file);
-
-                  /* if source and target folders are different, also tell
-                     the target folder to reload for the changes */
-                  if (thunar_file_has_parent (file))
+                  file = thunar_file_get(other_file, NULL);
+                  if (file != NULL && THUNAR_IS_FILE (file))
                     {
-                      other_parent = thunar_file_get_parent (file, NULL);
-                      if (other_parent &&
-                          !g_file_equal (thunar_file_get_file(folder->corresponding_file),
-                                         thunar_file_get_file(other_parent)))
+                      thunar_file_reload (file);
+
+                      /* if source and target folders are different, also tell
+                         the target folder to reload for the changes */
+                      if (thunar_file_has_parent (file))
                         {
-                          thunar_file_reload (other_parent);
-                          g_object_unref (other_parent);
+                          other_parent = thunar_file_get_parent (file, NULL);
+                          if (other_parent &&
+                              !g_file_equal (thunar_file_get_file(folder->corresponding_file),
+                                             thunar_file_get_file(other_parent)))
+                            {
+                              thunar_file_reload (other_parent);
+                              g_object_unref (other_parent);
+                            }
                         }
-                    }
 
-                  /* drop reference on the other file */
-                  g_object_unref (file);
+                      /* drop reference on the other file */
+                      g_object_unref (file);
+                    }
                 }
 
               /* reload the folder of the source file */
