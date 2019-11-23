--- src/3rdparty/chromium/third_party/webrtc/rtc_base/system/arch.h.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/third_party/webrtc/rtc_base/system/arch.h
@@ -47,6 +47,18 @@
 #elif defined(__pnacl__)
 #define WEBRTC_ARCH_32_BITS
 #define WEBRTC_ARCH_LITTLE_ENDIAN
+#elif defined(__PPC__)
+#define WEBRTC_ARCH_PPC_FAMILY
+#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
+#define WEBRTC_ARCH_LITTLE_ENDIAN
+#else
+#define WEBRTC_ARCH_BIG_ENDIAN
+#endif
+#if defined(__LP64__)
+#define WEBRTC_ARCH_64_BITS
+#else
+#define WEBRTC_ARCH_32_BITS
+#endif
 #else
 #error Please add support for your architecture in typedefs.h
 #endif
