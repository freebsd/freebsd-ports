--- ./third_party/WebKit/Source/wtf/ByteSwap.h.orig	2014-04-30 22:47:16.000000000 +0200
+++ ./third_party/WebKit/Source/wtf/ByteSwap.h	2014-05-04 14:38:48.000000000 +0200
@@ -52,14 +52,20 @@
 
 #else
 
+#ifndef bswap64
 ALWAYS_INLINE uint64_t bswap64(uint64_t x) { return __builtin_bswap64(x); }
+#endif
+#ifndef bswap32
 ALWAYS_INLINE uint32_t bswap32(uint32_t x) { return __builtin_bswap32(x); }
+#endif
 // GCC 4.6 lacks __builtin_bswap16. Newer versions have it but we support 4.6.
+#ifndef bswap16
 #if COMPILER(CLANG)
 ALWAYS_INLINE uint16_t bswap16(uint16_t x) { return __builtin_bswap16(x); }
 #else
 inline uint16_t bswap16(uint16_t x) { return ((x & 0xff00) >> 8) | ((x & 0x00ff) << 8); }
 #endif
+#endif
 
 #endif
 
