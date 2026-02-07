--- src/intrin_portable.h.orig	2024-01-12 23:32:27 UTC
+++ src/intrin_portable.h
@@ -186,11 +186,11 @@ FORCE_INLINE uint32_t rx_get_rounding_mode() {
 #undef pixel
 #undef bool
 
-typedef __vector uint8_t __m128i;
-typedef __vector uint32_t __m128l;
-typedef __vector int      __m128li;
-typedef __vector uint64_t __m128ll;
-typedef __vector double __m128d;
+typedef vector unsigned char __m128i;
+typedef vector unsigned int __m128l;
+typedef vector int      __m128li;
+typedef vector unsigned long long __m128ll;
+typedef vector double __m128d;
 
 typedef __m128i rx_vec_i128;
 typedef __m128d rx_vec_f128;
@@ -209,7 +209,7 @@ typedef union{
 #define rx_prefetch_t0(x)
 
 /* Splat 64-bit long long to 2 64-bit long longs */
-FORCE_INLINE __m128i vec_splat2sd (int64_t scalar)
+FORCE_INLINE __m128i vec_splat2sd (long long scalar)
 { return (__m128i) vec_splats (scalar); }
 
 FORCE_INLINE rx_vec_f128 rx_load_vec_f128(const double* pd) {
