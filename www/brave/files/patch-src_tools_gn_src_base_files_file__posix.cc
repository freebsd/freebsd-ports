--- src/tools/gn/src/base/files/file_posix.cc.orig	2026-10-18 18:43:23 UTC
+++ src/tools/gn/src/base/files/file_posix.cc
@@ -359,7 +359,7 @@ void File::DoInitialize(const FilePath&
 bool File::Flush() {
   DCHECK(IsValid());
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   return !HANDLE_EINTR(fdatasync(file_.get()));
 #else
   return !HANDLE_EINTR(fsync(file_.get()));
