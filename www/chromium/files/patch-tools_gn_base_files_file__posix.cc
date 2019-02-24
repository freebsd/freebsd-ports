--- tools/gn/base/files/file_posix.cc.orig	2019-02-06 23:16:22.000000000 +0100
+++ tools/gn/base/files/file_posix.cc	2019-02-08 18:18:17.423059000 +0100
@@ -414,7 +414,7 @@
 bool File::Flush() {
   DCHECK(IsValid());
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   return !HANDLE_EINTR(fdatasync(file_.get()));
 #else
   return !HANDLE_EINTR(fsync(file_.get()));
