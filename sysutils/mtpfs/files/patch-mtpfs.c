--- mtpfs.c.orig	Sun Jul  1 11:45:55 2007
+++ mtpfs.c	Sun Jul  1 11:46:30 2007
@@ -921,7 +921,7 @@
 */
 
 static int
-mtpfs_statfs (const char *path, struct statfs *stbuf)
+mtpfs_statfs (const char *path, struct statvfs *stbuf)
 {
     if (DEBUG) g_debug ("mtpfs_statfs");
     stbuf->f_bsize=1024;
