--- src/3rdparty/gn/src/base/files/file_posix.cc.orig	2023-08-16 19:50:41 UTC
+++ src/3rdparty/gn/src/base/files/file_posix.cc
@@ -371,7 +371,7 @@ bool File::Flush() {
 bool File::Flush() {
   DCHECK(IsValid());
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   return !HANDLE_EINTR(fdatasync(file_.get()));
 #else
   return !HANDLE_EINTR(fsync(file_.get()));
