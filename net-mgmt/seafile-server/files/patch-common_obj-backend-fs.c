--- common/obj-backend-fs.c.orig	2016-10-09 09:30:49 UTC
+++ common/obj-backend-fs.c
@@ -101,7 +101,7 @@ obj_backend_fs_read (ObjBackend *bend,
 static int
 fsync_obj_contents (int fd)
 {
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD__)
     /* Some file systems may not support fsync().
      * In this case, just skip the error.
      */
@@ -153,7 +153,7 @@ fsync_obj_contents (int fd)
 static int
 rename_and_sync (const char *tmp_path, const char *obj_path)
 {
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD__)
     char *parent_dir;
     int ret = 0;
 
