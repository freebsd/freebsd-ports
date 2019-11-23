--- src/3rdparty/chromium/third_party/boringssl/src/crypto/fipsmodule/modes/gcm.c.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/third_party/boringssl/src/crypto/fipsmodule/modes/gcm.c
@@ -78,6 +78,14 @@
     }                                                                 \
   } while (0)
 
+#ifdef OPENSSL_BIGENDIAN
+#define GCM_bswap4(x) (x)
+#define GCM_bswap8(x) (x)
+#else
+#define GCM_bswap4 CRYPTO_bswap4
+#define GCM_bswap8 CRYPTO_bswap8
+#endif
+
 // kSizeTWithoutLower4Bits is a mask that can be used to zero the lower four
 // bits of a |size_t|.
 static const size_t kSizeTWithoutLower4Bits = (size_t) -16;
@@ -173,8 +181,8 @@ static void gcm_gmult_4bit(uint64_t Xi[2], const u128 
     Z.lo ^= Htable[nlo].lo;
   }
 
-  Xi[0] = CRYPTO_bswap8(Z.hi);
-  Xi[1] = CRYPTO_bswap8(Z.lo);
+  Xi[0] = GCM_bswap8(Z.hi);
+  Xi[1] = GCM_bswap8(Z.lo);
 }
 
 // Streamed gcm_mult_4bit, see CRYPTO_gcm128_[en|de]crypt for
@@ -233,8 +241,8 @@ static void gcm_ghash_4bit(uint64_t Xi[2], const u128 
       Z.lo ^= Htable[nlo].lo;
     }
 
-    Xi[0] = CRYPTO_bswap8(Z.hi);
-    Xi[1] = CRYPTO_bswap8(Z.lo);
+    Xi[0] = GCM_bswap8(Z.hi);
+    Xi[1] = GCM_bswap8(Z.lo);
   } while (inp += 16, len -= 16);
 }
 #else  // GHASH_ASM
@@ -360,8 +368,8 @@ void CRYPTO_ghash_init(gmult_func *out_mult, ghash_fun
   OPENSSL_memcpy(H.c, gcm_key, 16);
 
   // H is stored in host byte order
-  H.u[0] = CRYPTO_bswap8(H.u[0]);
-  H.u[1] = CRYPTO_bswap8(H.u[1]);
+  H.u[0] = GCM_bswap8(H.u[0]);
+  H.u[1] = GCM_bswap8(H.u[1]);
 
   OPENSSL_memcpy(out_key, H.c, 16);
 
@@ -474,15 +482,15 @@ void CRYPTO_gcm128_setiv(GCM128_CONTEXT *ctx, const AE
       GCM_MUL(ctx, Yi);
     }
     len0 <<= 3;
-    ctx->Yi.u[1] ^= CRYPTO_bswap8(len0);
+    ctx->Yi.u[1] ^= GCM_bswap8(len0);
 
     GCM_MUL(ctx, Yi);
-    ctr = CRYPTO_bswap4(ctx->Yi.d[3]);
+    ctr = GCM_bswap4(ctx->Yi.d[3]);
   }
 
   (*ctx->gcm_key.block)(ctx->Yi.c, ctx->EK0.c, key);
   ++ctr;
-  ctx->Yi.d[3] = CRYPTO_bswap4(ctr);
+  ctx->Yi.d[3] = GCM_bswap4(ctr);
 }
 
 int CRYPTO_gcm128_aad(GCM128_CONTEXT *ctx, const uint8_t *aad, size_t len) {
@@ -580,7 +588,7 @@ int CRYPTO_gcm128_encrypt(GCM128_CONTEXT *ctx, const A
     ctx->ares = 0;
   }
 
-  ctr = CRYPTO_bswap4(ctx->Yi.d[3]);
+  ctr = GCM_bswap4(ctx->Yi.d[3]);
 
   n = ctx->mres;
   if (n) {
@@ -602,7 +610,7 @@ int CRYPTO_gcm128_encrypt(GCM128_CONTEXT *ctx, const A
       if (n == 0) {
         (*block)(ctx->Yi.c, ctx->EKi.c, key);
         ++ctr;
-        ctx->Yi.d[3] = CRYPTO_bswap4(ctr);
+        ctx->Yi.d[3] = GCM_bswap4(ctr);
       }
       ctx->Xi.c[n] ^= out[i] = in[i] ^ ctx->EKi.c[n];
       n = (n + 1) % 16;
@@ -621,7 +629,7 @@ int CRYPTO_gcm128_encrypt(GCM128_CONTEXT *ctx, const A
     while (j) {
       (*block)(ctx->Yi.c, ctx->EKi.c, key);
       ++ctr;
-      ctx->Yi.d[3] = CRYPTO_bswap4(ctr);
+      ctx->Yi.d[3] = GCM_bswap4(ctr);
       for (size_t i = 0; i < 16; i += sizeof(size_t)) {
         store_word_le(out + i,
                       load_word_le(in + i) ^ ctx->EKi.t[i / sizeof(size_t)]);
@@ -638,7 +646,7 @@ int CRYPTO_gcm128_encrypt(GCM128_CONTEXT *ctx, const A
     while (len >= 16) {
       (*block)(ctx->Yi.c, ctx->EKi.c, key);
       ++ctr;
-      ctx->Yi.d[3] = CRYPTO_bswap4(ctr);
+      ctx->Yi.d[3] = GCM_bswap4(ctr);
       for (size_t i = 0; i < 16; i += sizeof(size_t)) {
         store_word_le(out + i,
                       load_word_le(in + i) ^ ctx->EKi.t[i / sizeof(size_t)]);
@@ -653,7 +661,7 @@ int CRYPTO_gcm128_encrypt(GCM128_CONTEXT *ctx, const A
   while (len >= 16) {
     (*block)(ctx->Yi.c, ctx->EKi.c, key);
     ++ctr;
-    ctx->Yi.d[3] = CRYPTO_bswap4(ctr);
+    ctx->Yi.d[3] = GCM_bswap4(ctr);
     for (size_t i = 0; i < 16; i += sizeof(size_t)) {
       size_t tmp = load_word_le(in + i) ^ ctx->EKi.t[i / sizeof(size_t)];
       store_word_le(out + i, tmp);
@@ -668,7 +676,7 @@ int CRYPTO_gcm128_encrypt(GCM128_CONTEXT *ctx, const A
   if (len) {
     (*block)(ctx->Yi.c, ctx->EKi.c, key);
     ++ctr;
-    ctx->Yi.d[3] = CRYPTO_bswap4(ctr);
+    ctx->Yi.d[3] = GCM_bswap4(ctr);
     while (len--) {
       ctx->Xi.c[n] ^= out[n] = in[n] ^ ctx->EKi.c[n];
       ++n;
@@ -707,7 +715,7 @@ int CRYPTO_gcm128_decrypt(GCM128_CONTEXT *ctx, const A
     ctx->ares = 0;
   }
 
-  ctr = CRYPTO_bswap4(ctx->Yi.d[3]);
+  ctr = GCM_bswap4(ctx->Yi.d[3]);
 
   n = ctx->mres;
   if (n) {
@@ -732,7 +740,7 @@ int CRYPTO_gcm128_decrypt(GCM128_CONTEXT *ctx, const A
       if (n == 0) {
         (*block)(ctx->Yi.c, ctx->EKi.c, key);
         ++ctr;
-        ctx->Yi.d[3] = CRYPTO_bswap4(ctr);
+        ctx->Yi.d[3] = GCM_bswap4(ctr);
       }
       c = in[i];
       out[i] = c ^ ctx->EKi.c[n];
@@ -754,7 +762,7 @@ int CRYPTO_gcm128_decrypt(GCM128_CONTEXT *ctx, const A
     while (j) {
       (*block)(ctx->Yi.c, ctx->EKi.c, key);
       ++ctr;
-      ctx->Yi.d[3] = CRYPTO_bswap4(ctr);
+      ctx->Yi.d[3] = GCM_bswap4(ctr);
       for (size_t i = 0; i < 16; i += sizeof(size_t)) {
         store_word_le(out + i,
                       load_word_le(in + i) ^ ctx->EKi.t[i / sizeof(size_t)]);
@@ -771,7 +779,7 @@ int CRYPTO_gcm128_decrypt(GCM128_CONTEXT *ctx, const A
     while (len >= 16) {
       (*block)(ctx->Yi.c, ctx->EKi.c, key);
       ++ctr;
-      ctx->Yi.d[3] = CRYPTO_bswap4(ctr);
+      ctx->Yi.d[3] = GCM_bswap4(ctr);
       for (size_t i = 0; i < 16; i += sizeof(size_t)) {
         store_word_le(out + i,
                       load_word_le(in + i) ^ ctx->EKi.t[i / sizeof(size_t)]);
@@ -785,7 +793,7 @@ int CRYPTO_gcm128_decrypt(GCM128_CONTEXT *ctx, const A
   while (len >= 16) {
     (*block)(ctx->Yi.c, ctx->EKi.c, key);
     ++ctr;
-    ctx->Yi.d[3] = CRYPTO_bswap4(ctr);
+    ctx->Yi.d[3] = GCM_bswap4(ctr);
     for (size_t i = 0; i < 16; i += sizeof(size_t)) {
       size_t c = load_word_le(in + i);
       store_word_le(out + i, c ^ ctx->EKi.t[i / sizeof(size_t)]);
@@ -800,7 +808,7 @@ int CRYPTO_gcm128_decrypt(GCM128_CONTEXT *ctx, const A
   if (len) {
     (*block)(ctx->Yi.c, ctx->EKi.c, key);
     ++ctr;
-    ctx->Yi.d[3] = CRYPTO_bswap4(ctr);
+    ctx->Yi.d[3] = GCM_bswap4(ctr);
     while (len--) {
       uint8_t c = in[n];
       ctx->Xi.c[n] ^= c;
@@ -866,13 +874,13 @@ int CRYPTO_gcm128_encrypt_ctr32(GCM128_CONTEXT *ctx, c
   }
 #endif
 
-  ctr = CRYPTO_bswap4(ctx->Yi.d[3]);
+  ctr = GCM_bswap4(ctx->Yi.d[3]);
 
 #if defined(GHASH)
   while (len >= GHASH_CHUNK) {
     (*stream)(in, out, GHASH_CHUNK / 16, key, ctx->Yi.c);
     ctr += GHASH_CHUNK / 16;
-    ctx->Yi.d[3] = CRYPTO_bswap4(ctr);
+    ctx->Yi.d[3] = GCM_bswap4(ctr);
     GHASH(ctx, out, GHASH_CHUNK);
     out += GHASH_CHUNK;
     in += GHASH_CHUNK;
@@ -885,7 +893,7 @@ int CRYPTO_gcm128_encrypt_ctr32(GCM128_CONTEXT *ctx, c
 
     (*stream)(in, out, j, key, ctx->Yi.c);
     ctr += (unsigned int)j;
-    ctx->Yi.d[3] = CRYPTO_bswap4(ctr);
+    ctx->Yi.d[3] = GCM_bswap4(ctr);
     in += i;
     len -= i;
 #if defined(GHASH)
@@ -904,7 +912,7 @@ int CRYPTO_gcm128_encrypt_ctr32(GCM128_CONTEXT *ctx, c
   if (len) {
     (*ctx->gcm_key.block)(ctx->Yi.c, ctx->EKi.c, key);
     ++ctr;
-    ctx->Yi.d[3] = CRYPTO_bswap4(ctr);
+    ctx->Yi.d[3] = GCM_bswap4(ctr);
     while (len--) {
       ctx->Xi.c[n] ^= out[n] = in[n] ^ ctx->EKi.c[n];
       ++n;
@@ -970,14 +978,14 @@ int CRYPTO_gcm128_decrypt_ctr32(GCM128_CONTEXT *ctx, c
   }
 #endif
 
-  ctr = CRYPTO_bswap4(ctx->Yi.d[3]);
+  ctr = GCM_bswap4(ctx->Yi.d[3]);
 
 #if defined(GHASH)
   while (len >= GHASH_CHUNK) {
     GHASH(ctx, in, GHASH_CHUNK);
     (*stream)(in, out, GHASH_CHUNK / 16, key, ctx->Yi.c);
     ctr += GHASH_CHUNK / 16;
-    ctx->Yi.d[3] = CRYPTO_bswap4(ctr);
+    ctx->Yi.d[3] = GCM_bswap4(ctr);
     out += GHASH_CHUNK;
     in += GHASH_CHUNK;
     len -= GHASH_CHUNK;
@@ -1003,7 +1011,7 @@ int CRYPTO_gcm128_decrypt_ctr32(GCM128_CONTEXT *ctx, c
 #endif
     (*stream)(in, out, j, key, ctx->Yi.c);
     ctr += (unsigned int)j;
-    ctx->Yi.d[3] = CRYPTO_bswap4(ctr);
+    ctx->Yi.d[3] = GCM_bswap4(ctr);
     out += i;
     in += i;
     len -= i;
@@ -1011,7 +1019,7 @@ int CRYPTO_gcm128_decrypt_ctr32(GCM128_CONTEXT *ctx, c
   if (len) {
     (*ctx->gcm_key.block)(ctx->Yi.c, ctx->EKi.c, key);
     ++ctr;
-    ctx->Yi.d[3] = CRYPTO_bswap4(ctr);
+    ctx->Yi.d[3] = GCM_bswap4(ctr);
     while (len--) {
       uint8_t c = in[n];
       ctx->Xi.c[n] ^= c;
@@ -1036,8 +1044,8 @@ int CRYPTO_gcm128_finish(GCM128_CONTEXT *ctx, const ui
     GCM_MUL(ctx, Xi);
   }
 
-  alen = CRYPTO_bswap8(alen);
-  clen = CRYPTO_bswap8(clen);
+  alen = GCM_bswap8(alen);
+  clen = GCM_bswap8(clen);
 
   ctx->Xi.u[0] ^= alen;
   ctx->Xi.u[1] ^= clen;
