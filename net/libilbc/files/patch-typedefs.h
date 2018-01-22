--- typedefs.h.orig	2014-12-14 19:34:22 UTC
+++ typedefs.h
@@ -26,6 +26,12 @@
 #elif defined(__aarch64__)
 #define WEBRTC_ARCH_64_BITS
 #define WEBRTC_ARCH_LITTLE_ENDIAN
+#elif defined(__powerpc64__) || defined(__sparc64__)
+#define WEBRTC_ARCH_64_BITS
+#define WEBRTC_ARCH_BIG_ENDIAN
+#elif defined(__powerpc__)
+#define WEBRTC_ARCH_32_BITS
+#define WEBRTC_ARCH_BIG_ENDIAN
 #elif defined(_M_IX86) || defined(__i386__)
 #define WEBRTC_ARCH_X86_FAMILY
 #define WEBRTC_ARCH_X86
