--- base/files/file_util.h.orig	2017-06-05 19:03:00 UTC
+++ base/files/file_util.h
@@ -406,7 +406,7 @@ BASE_EXPORT bool VerifyPathControlledByAdmin(const bas
 // the directory |path|, in the number of FilePath::CharType, or -1 on failure.
 BASE_EXPORT int GetMaximumPathComponentLength(const base::FilePath& path);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // Broad categories of file systems as returned by statfs() on Linux.
 enum FileSystemType {
   FILE_SYSTEM_UNKNOWN,  // statfs failed.
