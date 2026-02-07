--- core/io/FileSystem.cpp.orig	2021-10-02 16:31:29 UTC
+++ core/io/FileSystem.cpp
@@ -429,7 +429,11 @@ bool FileSystem::setWorkingDirectory(const Path& path)
 Expected<Path> FileSystem::getDirectoryOfExecutable() {
 #ifndef SPH_WIN
     char result[4096] = { '\0' };
+#if defined(__FreeBSD__)
+    ssize_t count = readlink("/proc/curproc/file", result, sizeof(result));
+#else
     ssize_t count = readlink("/proc/self/exe", result, sizeof(result));
+#endif
     if (count != -1) {
         Path path(String::fromUtf8(result));
         return path.parentPath();
