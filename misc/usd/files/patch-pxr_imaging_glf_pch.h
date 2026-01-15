--- pxr/imaging/glf/pch.h.orig	2025-10-24 16:21:56 UTC
+++ pxr/imaging/glf/pch.h
@@ -26,6 +26,13 @@
 #include <unistd.h>
 #include <x86intrin.h>
 #endif
+#if defined(ARCH_OS_FREEBSD)
+#include <glob.h>
+#include <limits.h>
+#include <sys/param.h>
+#include <unistd.h>
+#include <x86intrin.h>
+#endif
 #if defined(ARCH_OS_WINDOWS)
 #ifndef WIN32_LEAN_AND_MEAN
 #define WIN32_LEAN_AND_MEAN
