diff --git a/modules/affile/affile.c b/modules/affile/affile.c
index 7746897..e145324 100644
--- modules/affile/affile.c
+++ modules/affile/affile.c
@@ -607,7 +607,7 @@ affile_dd_set_file_gid(LogDriver *s, const gchar *file_gid)
 }
 
 void 
-affile_dd_set_file_perm(LogDriver *s, mode_t file_perm)
+affile_dd_set_file_perm(LogDriver *s, gint file_perm)
 {
   AFFileDestDriver *self = (AFFileDestDriver *) s;
   
@@ -643,7 +643,7 @@ affile_dd_set_dir_gid(LogDriver *s, const gchar *dir_gid)
 }
 
 void 
-affile_dd_set_dir_perm(LogDriver *s, mode_t dir_perm)
+affile_dd_set_dir_perm(LogDriver *s, gint dir_perm)
 {
   AFFileDestDriver *self = (AFFileDestDriver *) s;
   
@@ -957,9 +957,9 @@ affile_dd_new(gchar *filename, guint32 flags)
   self->filename_template = log_template_new(configuration, NULL, filename);
   self->flags = flags;
   self->file_uid = self->file_gid = -1;
-  self->file_perm = (mode_t) -1;
+  self->file_perm = -1;
   self->dir_uid = self->dir_gid = -1;
-  self->dir_perm = (mode_t) -1;
+  self->dir_perm = -1;
   log_writer_options_defaults(&self->writer_options);
   if (strchr(filename, '$') == NULL)
     {
