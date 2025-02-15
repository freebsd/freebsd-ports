--- libs/miniwebrtc/typedefs.h.orig	2025-02-15 23:05:48 UTC
+++ libs/miniwebrtc/typedefs.h
@@ -76,6 +76,9 @@
 //#define WEBRTC_ARCH_ARMEL
 #define WEBRTC_ARCH_32_BITS
 #define WEBRTC_ARCH_LITTLE_ENDIAN
+#elif defined(__aarch64__)
+#define WEBRTC_ARCH_64_BITS
+#define WEBRTC_ARCH_LITTLE_ENDIAN
 #elif defined(__mips__)
 #define WEBRTC_ARCH_32_BITS
 #define WEBRTC_BIG_ENDIAN
