--- src/3rdparty/chromium/third_party/WebKit/Source/wtf/ByteSwap.h.orig	2017-01-26 00:49:28 UTC
+++ src/3rdparty/chromium/third_party/WebKit/Source/wtf/ByteSwap.h
@@ -60,15 +60,21 @@ ALWAYS_INLINE uint16_t bswap16(uint16_t 
 
 #else
 
+#ifndef bswap64
 ALWAYS_INLINE uint64_t bswap64(uint64_t x) {
   return __builtin_bswap64(x);
 }
+#endif
+#ifndef bswap32
 ALWAYS_INLINE uint32_t bswap32(uint32_t x) {
   return __builtin_bswap32(x);
 }
+#endif
+#ifndef bswap16
 ALWAYS_INLINE uint16_t bswap16(uint16_t x) {
   return __builtin_bswap16(x);
 }
+#endif
 
 #endif
 
