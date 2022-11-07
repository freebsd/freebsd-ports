--- include/brynet/base/Platform.hpp.orig	2022-11-07 05:36:34 UTC
+++ include/brynet/base/Platform.hpp
@@ -5,6 +5,8 @@
 #pragma comment(lib, "ws2_32")
 #elif defined __APPLE_CC__ || defined __APPLE__
 #define BRYNET_PLATFORM_DARWIN
+#elif defined __FreeBSD__
+#define BRYNET_PLATFORM_FREEBSD
 #else
 #define BRYNET_PLATFORM_LINUX
 #endif
