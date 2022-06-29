--- src/nautilus-thumbnails.c.orig	2022-06-29 19:28:36 UTC
+++ src/nautilus-thumbnails.c
@@ -530,9 +530,7 @@ thumbnail_thread_func (GTask        *task,
 
         pixbuf = gnome_desktop_thumbnail_factory_generate_thumbnail (thumbnail_factory,
                                                                      info->image_uri,
-                                                                     info->mime_type,
-                                                                     NULL,
-                                                                     &error);
+                                                                     info->mime_type);
 
         if (pixbuf)
         {
@@ -542,9 +540,7 @@ thumbnail_thread_func (GTask        *task,
             gnome_desktop_thumbnail_factory_save_thumbnail (thumbnail_factory,
                                                             pixbuf,
                                                             info->image_uri,
-                                                            current_orig_mtime,
-                                                            NULL,
-                                                            &error);
+                                                            current_orig_mtime);
             if (error)
             {
                 DEBUG ("(Thumbnail Thread) Saving thumbnail failed: %s (%s)\n",
@@ -561,8 +557,7 @@ thumbnail_thread_func (GTask        *task,
 
             gnome_desktop_thumbnail_factory_create_failed_thumbnail (thumbnail_factory,
                                                                      info->image_uri,
-                                                                     current_orig_mtime,
-                                                                     NULL, NULL);
+                                                                     current_orig_mtime);
         }
         /* We need to call nautilus_file_changed(), but I don't think that is
          *  thread safe. So add an idle handler and do it from the main loop. */
