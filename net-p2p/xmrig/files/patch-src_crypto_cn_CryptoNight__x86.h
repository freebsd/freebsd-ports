--- src/crypto/cn/CryptoNight_x86.h.orig	2023-02-02 04:51:11 UTC
+++ src/crypto/cn/CryptoNight_x86.h
@@ -80,7 +80,7 @@ static inline void do_skein_hash(const uint8_t *input,
 void (* const extra_hashes[4])(const uint8_t *, size_t, uint8_t *) = {do_blake_hash, do_groestl_hash, do_jh_hash, do_skein_hash};
 
 
-#if defined(__i386__) || defined(_M_IX86)
+#if (defined(__i386__) || defined(_M_IX86)) && !(defined(__clang__) && defined(__clang_major__) && (__clang_major__ >= 15))
 static inline int64_t _mm_cvtsi128_si64(__m128i a)
 {
     return ((uint64_t)(uint32_t)_mm_cvtsi128_si32(a) | ((uint64_t)(uint32_t)_mm_cvtsi128_si32(_mm_srli_si128(a, 4)) << 32));
