--- tools/gn/base/files/file_util.h.orig	2019-12-16 21:58:04 UTC
+++ tools/gn/base/files/file_util.h
@@ -360,7 +360,7 @@ bool VerifyPathControlledByAdmin(const base::FilePath&
 // the directory |path|, in the number of FilePath::CharType, or -1 on failure.
 int GetMaximumPathComponentLength(const base::FilePath& path);
 
-#if defined(OS_LINUX) || defined(OS_AIX)
+#if defined(OS_LINUX) || defined(OS_AIX) || defined(OS_BSD)
 // Broad categories of file systems as returned by statfs() on Linux.
 enum FileSystemType {
   FILE_SYSTEM_UNKNOWN,   // statfs failed.
