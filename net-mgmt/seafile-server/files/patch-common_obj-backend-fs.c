--- common/obj-backend-fs.c.orig	2019-12-23 10:30:49 UTC
+++ common/obj-backend-fs.c
@@ -95,7 +95,7 @@ obj_backend_fs_read (ObjBackend *bend,
 static int
 fsync_obj_contents (int fd)
 {
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD__)
     /* Some file systems may not support fsync().
      * In this case, just skip the error.
      */
@@ -147,7 +147,7 @@ fsync_obj_contents (int fd)
 static int
 rename_and_sync (const char *tmp_path, const char *obj_path)
 {
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD__)
     char *parent_dir;
     int ret = 0;
 
