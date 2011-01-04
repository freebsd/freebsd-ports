diff --git a/modules/affile/affile.h b/modules/affile/affile.h
index 1c1ff1e..9ec1493 100644
--- modules/affile/affile.h
+++ modules/affile/affile.h
@@ -83,10 +83,10 @@ void affile_dd_set_compress(LogDriver *s, gboolean compress);
 void affile_dd_set_encrypt(LogDriver *s, gboolean enable);
 void affile_dd_set_file_uid(LogDriver *s, const gchar *file_uid);
 void affile_dd_set_file_gid(LogDriver *s, const gchar *file_gid);
-void affile_dd_set_file_perm(LogDriver *s, mode_t file_perm);
+void affile_dd_set_file_perm(LogDriver *s, gint file_perm);
 void affile_dd_set_dir_uid(LogDriver *s, const gchar *dir_uid);
 void affile_dd_set_dir_gid(LogDriver *s, const gchar *dir_gid);
-void affile_dd_set_dir_perm(LogDriver *s, mode_t dir_perm);
+void affile_dd_set_dir_perm(LogDriver *s, gint dir_perm);
 void affile_dd_set_create_dirs(LogDriver *s, gboolean create_dirs);
 void affile_dd_set_fsync(LogDriver *s, gboolean enable);
 void affile_dd_set_overwrite_if_older(LogDriver *s, gint overwrite_if_older);
