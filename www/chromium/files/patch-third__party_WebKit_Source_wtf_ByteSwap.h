--- third_party/WebKit/Source/wtf/ByteSwap.h.orig	2016-03-25 13:05:01 UTC
+++ third_party/WebKit/Source/wtf/ByteSwap.h
@@ -52,9 +52,15 @@ ALWAYS_INLINE uint16_t bswap16(uint16_t 
 
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
 
