--- third_party/blink/renderer/platform/wtf/byte_swap.h.orig	2018-07-19 20:15:20.782500000 +0200
+++ third_party/blink/renderer/platform/wtf/byte_swap.h	2018-07-19 20:16:32.779700000 +0200
@@ -60,15 +60,21 @@
 
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
 
