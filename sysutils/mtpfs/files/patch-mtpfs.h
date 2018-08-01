--- mtpfs.h.orig	2012-02-24 04:37:14 UTC
+++ mtpfs.h
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
@@ -49,7 +51,7 @@ static int find_storage(const gchar * pa
 
 
     /* fuse functions */
-static void * mtpfs_init (void);
+static void * mtpfs_init (struct fuse_conn_info *);
 static int mtpfs_blank ();
 static int mtpfs_release (const char *path, struct fuse_file_info *fi);
 void mtpfs_destroy ();
@@ -62,7 +64,7 @@ static int mtpfs_write (const gchar * pa
 static int mtpfs_unlink (const gchar * path);
 static int mtpfs_mkdir (const char *path, mode_t mode);
 static int mtpfs_rmdir (const char *path);
-static int mtpfs_statfs (const char *path, struct statfs *stbuf);
+static int mtpfs_statfs (const char *path, struct statvfs *stbuf);
 int calc_length(int f);
 
 static LIBMTP_mtpdevice_t *device;
