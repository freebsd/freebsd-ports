--- stage0/src/runtime/io.cpp.orig	2025-05-06 09:12:17 UTC
+++ stage0/src/runtime/io.cpp
@@ -1253,7 +1253,13 @@ extern "C" LEAN_EXPORT obj_res lean_io_app_path(obj_ar
     char dest[PATH_MAX];
     memset(dest, 0, PATH_MAX);
     pid_t pid = getpid();
+#if defined(__linux__)
     snprintf(path, PATH_MAX, "/proc/%d/exe", pid);
+#elif defined(__FreeBSD__)
+    snprintf(path, PATH_MAX, "/proc/%d/file", pid);
+#else
+#   error "Unknown platform"
+#endif
     if (readlink(path, dest, PATH_MAX) == -1) {
         return io_result_mk_error("failed to locate application");
     } else {
