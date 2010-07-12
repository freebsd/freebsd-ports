--- src/fs.h.orig
+++ src/fs.h
@@ -28,7 +28,7 @@ void print_fs_size(struct text_object *, char *, int);
 void print_fs_used(struct text_object *, char *, int);
 void print_fs_type(struct text_object *, char *, int);
 
-void update_fs_stats(void);
+int update_fs_stats(void);
 struct fs_stat *prepare_fs_stat(const char *path);
 void clear_fs_stats(void);
 
