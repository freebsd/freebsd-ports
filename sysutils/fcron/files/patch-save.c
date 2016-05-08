Replace fdatasync() with fsync() because FreeBSD doesn't have fdatasync().

--- save.c.orig	2014-05-10 17:03:59 UTC
+++ save.c
@@ -311,8 +311,8 @@ write_file_to_disk(int fd, struct cf_t *
      * This is to avoid cases where the file name (meta-data) would be updated,
      * and there is a crash before the data is fully written: not sure if that
      * is possible, but better safe than sorry! */
-    if (fdatasync(fd) < 0) {
-        error_e("could not fdatasync() %s's fcrontab", file->cf_user);
+    if (fsync(fd) < 0) {
+        error_e("could not fsync() %s's fcrontab", file->cf_user);
         return ERR;
     }
 
