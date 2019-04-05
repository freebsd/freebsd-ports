--- base/files/file_util.h.orig	2019-03-11 22:00:51 UTC
+++ base/files/file_util.h
@@ -445,7 +445,7 @@ BASE_EXPORT bool VerifyPathControlledByAdmin(const bas
 // the directory |path|, in the number of FilePath::CharType, or -1 on failure.
 BASE_EXPORT int GetMaximumPathComponentLength(const base::FilePath& path);
 
-#if defined(OS_LINUX) || defined(OS_AIX)
+#if defined(OS_LINUX) || defined(OS_AIX) || defined(OS_BSD)
 // Broad categories of file systems as returned by statfs() on Linux.
 enum FileSystemType {
   FILE_SYSTEM_UNKNOWN,  // statfs failed.
