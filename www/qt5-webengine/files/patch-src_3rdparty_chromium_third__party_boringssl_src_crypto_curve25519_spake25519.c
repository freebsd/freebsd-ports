--- src/3rdparty/chromium/third_party/boringssl/src/crypto/curve25519/spake25519.c.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/third_party/boringssl/src/crypto/curve25519/spake25519.c
@@ -339,8 +339,17 @@ static void scalar_double(scalar *s) {
   uint32_t carry = 0;
 
   for (size_t i = 0; i < 8; i++) {
-    const uint32_t carry_out = s->words[i] >> 31;
-    s->words[i] = (s->words[i] << 1) | carry;
+#ifdef OPENSSL_BIGENDIAN
+    const uint32_t si = CRYPTO_bswap4(s->words[i]);
+#else
+    const uint32_t si = s->words[i];
+#endif
+    const uint32_t carry_out = si >> 31;
+#ifdef OPENSSL_BIGENDIAN
+    s->words[i] = CRYPTO_bswap4((si << 1) | carry);
+#else
+    s->words[i] = (si << 1) | carry;
+#endif
     carry = carry_out;
   }
 }
@@ -350,8 +359,13 @@ static void scalar_add(scalar *dest, const scalar *src
   uint32_t carry = 0;
 
   for (size_t i = 0; i < 8; i++) {
+#ifdef OPENSSL_BIGENDIAN
+    uint64_t tmp = ((uint64_t)CRYPTO_bswap4(dest->words[i]) + CRYPTO_bswap4(src->words[i])) + carry;
+    dest->words[i] = CRYPTO_bswap4((uint32_t)tmp);
+#else
     uint64_t tmp = ((uint64_t)dest->words[i] + src->words[i]) + carry;
     dest->words[i] = (uint32_t)tmp;
+#endif
     carry = (uint32_t)(tmp >> 32);
   }
 }
