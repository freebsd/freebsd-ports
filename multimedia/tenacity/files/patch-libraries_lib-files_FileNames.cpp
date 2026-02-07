--- libraries/lib-files/FileNames.cpp.orig	2025-10-26 07:26:25 UTC
+++ libraries/lib-files/FileNames.cpp
@@ -737,6 +737,8 @@ bool FileNames::IsOnFATFileSystem(const FilePath &path
    return 0 == strcmp(fs.f_fstypename, "msdos");
 }
 #elif defined(__FreeBSD__)
+#include <sys/param.h>
+#include <sys/mount.h>
 bool FileNames::IsOnFATFileSystem(const FilePath &path)
 {
    struct statfs fs;
