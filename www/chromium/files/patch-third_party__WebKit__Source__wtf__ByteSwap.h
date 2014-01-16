--- third_party/WebKit/Source/wtf/ByteSwap.h.orig	2014-01-07 21:06:25.000000000 +0100
+++ third_party/WebKit/Source/wtf/ByteSwap.h	2014-01-13 01:21:42.000000000 +0100
@@ -52,8 +52,13 @@
 
 #else
 
+#ifndef bswap64
 inline uint64_t bswap64(uint64_t x) { return __builtin_bswap64(x); }
+#endif
+#ifndef bswap32
 inline uint32_t bswap32(uint32_t x) { return __builtin_bswap32(x); }
+#endif
+#ifndef bswap16
 // GCC lacks bswap16.
 #if COMPILER(CLANG)
 inline uint16_t bswap16(uint16_t x) { return __builtin_bswap16(x); }
@@ -61,6 +66,7 @@
 // GCC lacks __builtin_bswap16.
 inline uint16_t bswap16(uint16_t x) { return ((x & 0xff00) >> 8) | ((x & 0x00ff) << 8); }
 #endif
+#endif
 
 #endif
 
