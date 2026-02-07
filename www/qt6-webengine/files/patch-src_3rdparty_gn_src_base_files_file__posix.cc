--- src/3rdparty/gn/src/base/files/file_posix.cc.orig	2025-02-21 12:29:33 UTC
+++ src/3rdparty/gn/src/base/files/file_posix.cc
@@ -359,7 +359,7 @@ bool File::Flush() {
 bool File::Flush() {
   DCHECK(IsValid());
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   return !HANDLE_EINTR(fdatasync(file_.get()));
 #else
   return !HANDLE_EINTR(fsync(file_.get()));
