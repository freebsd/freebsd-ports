--- src/3rdparty/chromium/third_party/boringssl/src/crypto/chacha/chacha.c.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/third_party/boringssl/src/crypto/chacha/chacha.c
@@ -29,6 +29,14 @@
   (((uint32_t)((p)[0])) | ((uint32_t)((p)[1]) << 8) | \
    ((uint32_t)((p)[2]) << 16) | ((uint32_t)((p)[3]) << 24))
 
+#define U32TO8_LITTLE(p, v)    \
+  {                            \
+    (p)[0] = (v >> 0) & 0xff;  \
+    (p)[1] = (v >> 8) & 0xff;  \
+    (p)[2] = (v >> 16) & 0xff; \
+    (p)[3] = (v >> 24) & 0xff; \
+  }
+
 // sigma contains the ChaCha constants, which happen to be an ASCII string.
 static const uint8_t sigma[16] = { 'e', 'x', 'p', 'a', 'n', 'd', ' ', '3',
                                    '2', '-', 'b', 'y', 't', 'e', ' ', 'k' };
@@ -45,10 +53,28 @@ static const uint8_t sigma[16] = { 'e', 'x', 'p', 'a',
 void CRYPTO_hchacha20(uint8_t out[32], const uint8_t key[32],
                       const uint8_t nonce[16]) {
   uint32_t x[16];
-  OPENSSL_memcpy(x, sigma, sizeof(sigma));
-  OPENSSL_memcpy(&x[4], key, 32);
-  OPENSSL_memcpy(&x[12], nonce, 16);
+  int i;
 
+  x[0] = U8TO32_LITTLE(sigma + 0);
+  x[1] = U8TO32_LITTLE(sigma + 4);
+  x[2] = U8TO32_LITTLE(sigma + 8);
+  x[3] = U8TO32_LITTLE(sigma + 12);
+
+  x[4] = U8TO32_LITTLE(key + 0);
+  x[5] = U8TO32_LITTLE(key + 4);
+  x[6] = U8TO32_LITTLE(key + 8);
+  x[7] = U8TO32_LITTLE(key + 12);
+
+  x[8] = U8TO32_LITTLE(key + 16);
+  x[9] = U8TO32_LITTLE(key + 20);
+  x[10] = U8TO32_LITTLE(key + 24);
+  x[11] = U8TO32_LITTLE(key + 28);
+
+  x[12] = U8TO32_LITTLE(nonce + 0);
+  x[13] = U8TO32_LITTLE(nonce + 4);
+  x[14] = U8TO32_LITTLE(nonce + 8);
+  x[15] = U8TO32_LITTLE(nonce + 12);
+
   for (size_t i = 0; i < 20; i += 2) {
     QUARTERROUND(0, 4, 8, 12)
     QUARTERROUND(1, 5, 9, 13)
@@ -60,8 +86,10 @@ void CRYPTO_hchacha20(uint8_t out[32], const uint8_t k
     QUARTERROUND(3, 4, 9, 14)
   }
 
-  OPENSSL_memcpy(out, &x[0], sizeof(uint32_t) * 4);
-  OPENSSL_memcpy(&out[16], &x[12], sizeof(uint32_t) * 4);
+  for (i = 0; i < 4; ++i) {
+    U32TO8_LITTLE(out + 4 * i, x[i]);
+    U32TO8_LITTLE(&out[16] + 4 * i, x[12+i]);
+  }
 }
 
 #if !defined(OPENSSL_NO_ASM) &&                         \
@@ -104,14 +132,6 @@ void CRYPTO_chacha_20(uint8_t *out, const uint8_t *in,
 }
 
 #else
-
-#define U32TO8_LITTLE(p, v)    \
-  {                            \
-    (p)[0] = (v >> 0) & 0xff;  \
-    (p)[1] = (v >> 8) & 0xff;  \
-    (p)[2] = (v >> 16) & 0xff; \
-    (p)[3] = (v >> 24) & 0xff; \
-  }
 
 // chacha_core performs 20 rounds of ChaCha on the input words in
 // |input| and writes the 64 output bytes to |output|.
