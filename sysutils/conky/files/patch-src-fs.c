--- src/fs.c.orig
+++ src/fs.c
@@ -65,13 +65,13 @@ static void update_fs_stat(struct fs_stat *fs);
 
 void get_fs_type(const char *path, char *result);
 
-void update_fs_stats(void)
+int update_fs_stats(void)
 {
 	unsigned i;
 	static double last_fs_update = 0.0;
 
 	if (current_update_time - last_fs_update < 13)
-		return;
+		return 0;
 
 	for (i = 0; i < MAX_FS_STATS; ++i) {
 		if (fs_stats[i].set) {
@@ -79,6 +79,7 @@ void update_fs_stats(void)
 		}
 	}
 	last_fs_update = current_update_time;
+	return 0;
 }
 
 void clear_fs_stats(void)
