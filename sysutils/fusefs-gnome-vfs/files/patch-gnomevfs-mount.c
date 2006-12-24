--- gnomevfs-mount.c.orig	Sat Dec 23 21:52:20 2006
+++ gnomevfs-mount.c	Sat Dec 23 21:55:02 2006
@@ -31,7 +31,8 @@
 #define _GNU_SOURCE 1
 #endif
 
-#define FUSE_USE_VERSION 22
+
+#define FUSE_USE_VERSION 25
 
 #include <fuse.h>
 #include <stdio.h>
@@ -40,7 +41,14 @@
 #include <fcntl.h>
 #include <dirent.h>
 #include <errno.h>
+
+#ifdef __FreeBSD__
+#define ENODATA ENOATTR
+#define EGREGIOUS EDOOFUS
+#else
 #include <sys/statfs.h>
+#endif
+
 #include <sys/types.h>
 #include <sys/stat.h>
 
@@ -705,7 +713,7 @@
     char *full_path;
     GnomeVFSOpenMode flags = GNOME_VFS_OPEN_RANDOM;
     GnomeVFSResult result;
-    GnomeVFSHandle *handle = (GnomeVFSHandle *) fi->fh;
+    GnomeVFSHandle *handle = (GnomeVFSHandle *) (int) fi->fh;
 
     full_path = g_strdup_printf("%s/%s", mount_name, path);
 
@@ -735,7 +743,7 @@
 {
     int res;
     GnomeVFSResult result;
-    GnomeVFSHandle *handle = (GnomeVFSHandle *) fi->fh;
+    GnomeVFSHandle *handle = (GnomeVFSHandle *) (int) fi->fh;
     GnomeVFSFileSize nread;
     (void) path;
 
@@ -760,7 +768,7 @@
 {
     int res;
     GnomeVFSResult result;
-    GnomeVFSHandle *handle = (GnomeVFSHandle *) fi->fh;
+    GnomeVFSHandle *handle = (GnomeVFSHandle *) (int) fi->fh;
     GnomeVFSFileSize nwrite;
     (void) path;
 
@@ -790,7 +798,7 @@
 
 static int xmp_release(const char *path, struct fuse_file_info *fi)
 {
-    GnomeVFSHandle *handle = (GnomeVFSHandle *) fi->fh;
+    GnomeVFSHandle *handle = (GnomeVFSHandle *) (int) fi->fh;
     (void) path;
 
     //g_debug("%s %s", __FUNCTION__, path);
