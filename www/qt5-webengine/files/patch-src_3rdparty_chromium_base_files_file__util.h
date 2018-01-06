--- src/3rdparty/chromium/base/files/file_util.h.orig	2017-01-26 00:49:07 UTC
+++ src/3rdparty/chromium/base/files/file_util.h
@@ -404,7 +404,7 @@ BASE_EXPORT bool VerifyPathControlledByA
 // the directory |path|, in the number of FilePath::CharType, or -1 on failure.
 BASE_EXPORT int GetMaximumPathComponentLength(const base::FilePath& path);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 // Broad categories of file systems as returned by statfs() on Linux.
 enum FileSystemType {
   FILE_SYSTEM_UNKNOWN,  // statfs failed.
