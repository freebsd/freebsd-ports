--- src/parnell/parnell_unlink.c.orig	2024-09-05 20:45:46 UTC
+++ src/parnell/parnell_unlink.c
@@ -75,7 +75,7 @@ parnell_status_t parnell_unlink(char *fpath) {
   }
 
   /* try to delete file and catch errors but don't act on them */
-  if (lstat(fpath, &info)) {
+  if (stat(fpath, &info)) {
     /* if error other than "No such file or directory", report it */
     if (errno != ENOENT) {
       perror("parnell_unlink: error while calling stat on file");
