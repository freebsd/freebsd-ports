--- base/files/file_util.h.orig	2017-07-25 21:04:48.000000000 +0200
+++ base/files/file_util.h	2017-07-29 00:57:11.269678000 +0200
@@ -406,7 +406,7 @@
 // the directory |path|, in the number of FilePath::CharType, or -1 on failure.
 BASE_EXPORT int GetMaximumPathComponentLength(const base::FilePath& path);
 
-#if defined(OS_LINUX) || defined(OS_AIX)
+#if defined(OS_LINUX) || defined(OS_AIX) || defined(OS_BSD)
 // Broad categories of file systems as returned by statfs() on Linux.
 enum FileSystemType {
   FILE_SYSTEM_UNKNOWN,  // statfs failed.
