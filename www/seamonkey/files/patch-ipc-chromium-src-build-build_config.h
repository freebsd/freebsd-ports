--- mozilla/ipc/chromium/src/build/build_config.h~
+++ mozilla/ipc/chromium/src/build/build_config.h
@@ -17,7 +17,7 @@
 // A set of macros to use for platform detection.
 #if defined(__APPLE__)
 #define OS_MACOSX 1
-#elif defined(__linux__) || defined(ANDROID)
+#elif defined(__FreeBSD__) || defined(ANDROID)
 #define OS_LINUX 1
 #elif defined(_WIN32)
 #define OS_WIN 1
