--- deps/uv/src/unix/fs.c.orig	2011-09-14 16:00:16.000000000 +0800
+++ deps/uv/src/unix/fs.c	2011-09-14 16:19:48.000000000 +0800
@@ -434,7 +434,7 @@
 
 int uv_fs_fdatasync(uv_loop_t* loop, uv_fs_t* req, uv_file file, uv_fs_cb cb) {
   char* path = NULL;
-  WRAP_EIO(UV_FS_FDATASYNC, eio_fdatasync, fdatasync, ARGS1(file))
+  WRAP_EIO(UV_FS_FSYNC, eio_fsync, fsync, ARGS1(file))
 }
 
 
