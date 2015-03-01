--- common/obj-backend-fs.c.orig	2015-01-28 02:14:45.000000000 -0500
+++ common/obj-backend-fs.c	2015-01-28 02:15:58.000000000 -0500
@@ -101,7 +101,7 @@
 static int
 fsync_obj_contents (int fd)
 {
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD__)
     /* Some file systems may not support fsync().
      * In this case, just skip the error.
      */
@@ -153,7 +153,7 @@
 static int
 rename_and_sync (const char *tmp_path, const char *obj_path)
 {
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD__)
     char *parent_dir;
     int ret = 0;
 
