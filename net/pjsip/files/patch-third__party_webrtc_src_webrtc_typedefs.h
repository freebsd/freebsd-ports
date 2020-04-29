--- third_party/webrtc/src/webrtc/typedefs.h.orig	2017-01-07 23:05:15 UTC
+++ third_party/webrtc/src/webrtc/typedefs.h
@@ -48,7 +48,19 @@
 #define WEBRTC_ARCH_32_BITS
 #define WEBRTC_ARCH_LITTLE_ENDIAN
 #else
-#error Please add support for your architecture in typedefs.h
+/* instead of failing, use typical unix defines... */
+#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
+#define WEBRTC_ARCH_LITTLE_ENDIAN
+#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
+#define WEBRTC_ARCH_BIG_ENDIAN
+#else
+#error __BYTE_ORDER__ is not defined
+#endif
+#if defined(__LP64__)
+#define WEBRTC_ARCH_64_BITS
+#else
+#define WEBRTC_ARCH_32_BITS
+#endif
 #endif
 
 #if !(defined(WEBRTC_ARCH_LITTLE_ENDIAN) ^ defined(WEBRTC_ARCH_BIG_ENDIAN))
