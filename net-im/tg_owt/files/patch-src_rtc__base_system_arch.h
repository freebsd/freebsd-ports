--- src/rtc_base/system/arch.h.orig	2022-02-09 19:21:53 UTC
+++ src/rtc_base/system/arch.h
@@ -46,6 +46,13 @@
 #endif
 #if defined(__MIPSEL__)
 #define WEBRTC_ARCH_LITTLE_ENDIAN
+#elif defined(__powerpc64__)
+#define WEBRTC_ARCH_64_BITS
+#if defined(__BIG_ENDIAN__)
+#define WEBRTC_ARCH_BIG_ENDIAN
+#else
+#define WEBRTC_ARCH_LITTLE_ENDIAN
+#endif
 #else
 #define WEBRTC_ARCH_BIG_ENDIAN
 #endif
