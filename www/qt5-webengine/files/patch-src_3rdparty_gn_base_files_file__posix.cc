--- src/3rdparty/gn/base/files/file_posix.cc.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/gn/base/files/file_posix.cc
@@ -414,7 +414,7 @@ void File::DoInitialize(const FilePath& path, uint32_t
 bool File::Flush() {
   DCHECK(IsValid());
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   return !HANDLE_EINTR(fdatasync(file_.get()));
 #else
   return !HANDLE_EINTR(fsync(file_.get()));
