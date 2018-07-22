--- util/path.cpp.orig	2018-07-22 05:22:25 UTC
+++ util/path.cpp
@@ -82,7 +82,11 @@ std::string get_exe_location() {
     char dest[PATH_MAX];
     memset(dest, 0, PATH_MAX);
     pid_t pid = getpid();
+#if defined(__FreeBSD__)
+    snprintf(path, PATH_MAX, "/proc/%d/file", pid);
+#else
     snprintf(path, PATH_MAX, "/proc/%d/exe", pid);
+#endif
     if (readlink(path, dest, PATH_MAX) == -1) {
         throw exception("failed to locate Lean executable location");
     } else {
