Replace fdatasync() with fsync() because FreeBSD doesn't have fdatasync().

--- save.c.orig	2016-06-26 15:02:48 UTC
+++ save.c
@@ -315,8 +315,8 @@ write_file_to_disk(int fd, struct cf_t *
      * This is to avoid cases where the file name (meta-data) would be updated,
      * and there is a crash before the data is fully written: not sure if that
      * is possible, but better safe than sorry! */
-    if (fdatasync(fd) < 0) {
-        error_e("could not fdatasync() %s's fcrontab", file->cf_user);
+    if (fsync(fd) < 0) {
+        error_e("could not fsync() %s's fcrontab", file->cf_user);
         return ERR;
     }
 
