--- src/3rdparty/chromium/third_party/boringssl/src/crypto/fipsmodule/modes/polyval.c.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/third_party/boringssl/src/crypto/fipsmodule/modes/polyval.c
@@ -32,16 +32,26 @@ static void byte_reverse(polyval_block *b) {
 // the GHASH field, multiplies that by 'x' and serialises the result back into
 // |b|, but with GHASH's backwards bit ordering.
 static void reverse_and_mulX_ghash(polyval_block *b) {
+#ifdef OPENSSL_BIGENDIAN
+  uint64_t hi = CRYPTO_bswap8(b->u[0]);
+  uint64_t lo = CRYPTO_bswap8(b->u[1]);
+#else
   uint64_t hi = b->u[0];
   uint64_t lo = b->u[1];
+#endif
   const crypto_word_t carry = constant_time_eq_w(hi & 1, 1);
   hi >>= 1;
   hi |= lo << 63;
   lo >>= 1;
   lo ^= ((uint64_t) constant_time_select_w(carry, 0xe1, 0)) << 56;
 
+#ifdef OPENSSL_BIGENDIAN
+  b->u[0] = lo;
+  b->u[1] = hi;
+#else
   b->u[0] = CRYPTO_bswap8(lo);
   b->u[1] = CRYPTO_bswap8(hi);
+#endif
 }
 
 // POLYVAL(H, X_1, ..., X_n) =
