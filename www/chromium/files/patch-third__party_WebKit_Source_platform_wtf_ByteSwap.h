--- third_party/WebKit/Source/platform/wtf/ByteSwap.h.orig	2017-06-05 19:03:26 UTC
+++ third_party/WebKit/Source/platform/wtf/ByteSwap.h
@@ -60,15 +60,21 @@ ALWAYS_INLINE uint16_t Bswap16(uint16_t x) {
 
 #else
 
+#ifndef Bswap64
 ALWAYS_INLINE uint64_t Bswap64(uint64_t x) {
   return __builtin_bswap64(x);
 }
+#endif
+#ifndef Bswap32
 ALWAYS_INLINE uint32_t Bswap32(uint32_t x) {
   return __builtin_bswap32(x);
 }
+#endif
+#ifndef Bswap16
 ALWAYS_INLINE uint16_t Bswap16(uint16_t x) {
   return __builtin_bswap16(x);
 }
+#endif
 
 #endif
 
