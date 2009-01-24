--- mtpfs.h.orig	2009-01-04 03:03:56.000000000 +0800
+++ mtpfs.h	2009-01-04 03:05:16.000000000 +0800
@@ -18,8 +18,9 @@
 #include <fcntl.h>
 #include <dirent.h>
 #include <errno.h>
-#include <sys/statfs.h>
-
+#include <sys/param.h>
+#include <sys/mount.h>
+#include <sys/statvfs.h>
 #include <libmtp.h>
 #include <glib.h>
 #include <id3tag.h>
@@ -49,7 +50,7 @@
 static int mtpfs_unlink (const gchar * path);
 static int mtpfs_mkdir (const char *path, mode_t mode);
 static int mtpfs_rmdir (const char *path);
-static int mtpfs_statfs (const char *path, struct statfs *stbuf);
+static int mtpfs_statfs (const char *path, struct statvfs *stbuf);
 int calc_length(int f);
 
 
