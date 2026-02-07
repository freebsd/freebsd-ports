--- src/libmw/deps/ghc/include/ghc/filesystem.hpp.orig	2022-05-14 10:57:56.053289000 +0000
+++ src/libmw/deps/ghc/include/ghc/filesystem.hpp	2022-05-14 10:58:38.778321000 +0000
@@ -50,6 +50,12 @@
 
 #if defined(__APPLE__) && defined(__MACH__)
 #define GHC_OS_MACOS
+#elif defined(__FreeBSD__)
+// use FreeBSD int strerror_r() instead of GNU char *strerror_r()
+#define _POSIX_C_SOURCE 200112L
+#if defined(__clang__) && defined(_GNU_SOURCE)
+#undef _GNU_SOURCE
+#endif
 #elif defined(__linux__)
 #define GHC_OS_LINUX
 #elif defined(_WIN64)
