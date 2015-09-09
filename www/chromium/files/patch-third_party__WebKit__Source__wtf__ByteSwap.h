--- third_party/WebKit/Source/wtf/ByteSwap.h.orig	2015-08-22 15:03:03.000000000 -0400
+++ third_party/WebKit/Source/wtf/ByteSwap.h	2015-09-03 11:19:52.852584000 -0400
@@ -52,9 +52,15 @@
 
 #else
 
+#ifndef bswap64
 ALWAYS_INLINE uint64_t bswap64(uint64_t x) { return __builtin_bswap64(x); }
+#endif
+#ifndef bswap32
 ALWAYS_INLINE uint32_t bswap32(uint32_t x) { return __builtin_bswap32(x); }
+#endif
+#ifndef bswap16
 ALWAYS_INLINE uint16_t bswap16(uint16_t x) { return __builtin_bswap16(x); }
+#endif
 
 #endif
 
