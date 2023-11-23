--- src/3rdparty/chromium/third_party/dawn/src/dawn/common/Platform.h.orig	2023-04-05 11:05:06 UTC
+++ src/3rdparty/chromium/third_party/dawn/src/dawn/common/Platform.h
@@ -46,6 +46,11 @@
 #error "Unsupported Windows platform."
 #endif
 
+#elif defined(__OpenBSD__) || defined(__FreeBSD__)
+#define DAWN_PLATFORM_IS_LINUX 1
+#define DAWN_PLATFORM_IS_BSD 1
+#define DAWN_PLATFORM_IS_POSIX 1
+
 #elif defined(__linux__)
 #define DAWN_PLATFORM_IS_LINUX 1
 #define DAWN_PLATFORM_IS_POSIX 1
