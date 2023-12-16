--- src/3rdparty/chromium/third_party/angle/src/common/platform.h.orig	2022-02-07 13:39:41 UTC
+++ src/3rdparty/chromium/third_party/angle/src/common/platform.h
@@ -26,7 +26,15 @@
 #elif defined(__linux__) || defined(EMSCRIPTEN)
 #    define ANGLE_PLATFORM_LINUX 1
 #    define ANGLE_PLATFORM_POSIX 1
-#elif defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) ||              \
+#elif defined(__OpenBSD__)
+#    define ANGLE_PLATFORM_OPENBSD 1
+#    define ANGLE_PLATFORM_POSIX 1
+#    define ANGLE_PLATFORM_BSD 1
+#elif defined(__FreeBSD__)
+#    define ANGLE_PLATFORM_FREEBSD 1
+#    define ANGLE_PLATFORM_POSIX 1
+#    define ANGLE_PLATFORM_BSD 1
+#elif defined(__NetBSD__) ||              \
     defined(__DragonFly__) || defined(__sun) || defined(__GLIBC__) || defined(__GNU__) || \
     defined(__QNX__) || defined(__Fuchsia__) || defined(__HAIKU__)
 #    define ANGLE_PLATFORM_POSIX 1
