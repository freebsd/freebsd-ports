--- base/files/file_util.h.orig	2016-08-03 22:02:10.000000000 +0300
+++ base/files/file_util.h	2016-09-05 23:00:09.940024000 +0300
@@ -391,7 +391,7 @@
 // the directory |path|, in the number of FilePath::CharType, or -1 on failure.
 BASE_EXPORT int GetMaximumPathComponentLength(const base::FilePath& path);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // Broad categories of file systems as returned by statfs() on Linux.
 enum FileSystemType {
   FILE_SYSTEM_UNKNOWN,  // statfs failed.
