--- thunar/thunar-file.h.orig	2015-05-15 16:38:08 UTC
+++ thunar/thunar-file.h
@@ -238,11 +238,8 @@ const gchar      *thunar_file_get_icon_n
 
 void              thunar_file_watch                      (ThunarFile              *file);
 void              thunar_file_unwatch                    (ThunarFile              *file);
-
-void              thunar_file_reload                     (ThunarFile              *file);
+gboolean          thunar_file_reload                     (ThunarFile              *file);
 void              thunar_file_reload_idle                (ThunarFile              *file);
-void              thunar_file_reload_idle_timeout        (ThunarFile              *file,
-                                                          guint                    timeout);
 void              thunar_file_reload_parent              (ThunarFile              *file);
 
 void              thunar_file_destroy                    (ThunarFile              *file);
