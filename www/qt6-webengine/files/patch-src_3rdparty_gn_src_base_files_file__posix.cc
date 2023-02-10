--- src/3rdparty/gn/src/base/files/file_posix.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/gn/src/base/files/file_posix.cc
@@ -369,7 +369,7 @@ bool File::Flush() {
 bool File::Flush() {
   DCHECK(IsValid());
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   return !HANDLE_EINTR(fdatasync(file_.get()));
 #else
   return !HANDLE_EINTR(fsync(file_.get()));
