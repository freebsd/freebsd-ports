--- mtpfs.h.orig	Sun Jul  1 11:45:49 2007
+++ mtpfs.h	Sun Jul  1 11:46:22 2007
@@ -18,7 +18,9 @@
 #include <fcntl.h>
 #include <dirent.h>
 #include <errno.h>
-#include <sys/statfs.h>
+#include <sys/param.h>
+#include <sys/mount.h>
+#include <sys/statvfs.h>
 
 #include <libmtp.h>
 #include <glib.h>
@@ -48,7 +50,7 @@
 static int mtpfs_unlink (const gchar * path);
 static int mtpfs_mkdir (const char *path, mode_t mode);
 static int mtpfs_rmdir (const char *path);
-static int mtpfs_statfs (const char *path, struct statfs *stbuf);
+static int mtpfs_statfs (const char *path, struct statvfs *stbuf);
 
 
 static LIBMTP_mtpdevice_t *device;
