--- src/fs.c.orig	2012-05-03 21:08:27 UTC
+++ src/fs.c
@@ -118,9 +118,15 @@ struct fs_stat *prepare_fs_stat(const ch
 
 static void update_fs_stat(struct fs_stat *fs)
 {
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+	struct statfs s;
+
+	if (statfs(fs->path, &s) == 0) {
+#else
 	struct statfs64 s;
 
 	if (statfs64(fs->path, &s) == 0) {
+#endif
 		fs->size = (long long)s.f_blocks * s.f_bsize;
 		/* bfree (root) or bavail (non-roots) ? */
 		fs->avail = (long long)s.f_bavail * s.f_bsize;
