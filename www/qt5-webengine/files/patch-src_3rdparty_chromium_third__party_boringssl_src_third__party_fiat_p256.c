--- src/3rdparty/chromium/third_party/boringssl/src/third_party/fiat/p256.c.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/third_party/boringssl/src/third_party/fiat/p256.c
@@ -882,12 +882,24 @@ static void fe_tobytes(uint8_t out[NBYTES], const fe i
   }
 }
 
+#ifdef OPENSSL_BIGENDIAN
+static void fe_tobytes_be(uint8_t out[NBYTES], const fe in) {
+  for (int i = 0; i<NBYTES; i++) {
+    out[i ^ (BN_BYTES-1)] = (uint8_t)(in[i/sizeof(in[0])] >> (8*(i%sizeof(in[0]))));
+  }
+}
+#endif
+
 static void fe_frombytes(fe out, const uint8_t in[NBYTES]) {
   for (int i = 0; i<NLIMBS; i++) {
     out[i] = 0;
   }
   for (int i = 0; i<NBYTES; i++) {
+#ifdef OPENSSL_BIGENDIAN
+    out[i/sizeof(out[0])] |= ((limb_t)in[i ^ (BN_BYTES-1)]) << (8*(i%sizeof(out[0])));
+#else
     out[i/sizeof(out[0])] |= ((limb_t)in[i]) << (8*(i%sizeof(out[0])));
+#endif
   }
 }
 
@@ -906,7 +918,11 @@ static void fe_to_generic(EC_FELEM *out, const fe in) 
   OPENSSL_STATIC_ASSERT(
       256 / 8 == sizeof(BN_ULONG) * ((256 + BN_BITS2 - 1) / BN_BITS2),
       "fe_tobytes leaves bytes uninitialized");
+#ifdef OPENSSL_BIGENDIAN
+  fe_tobytes_be(out->bytes, in);
+#else
   fe_tobytes(out->bytes, in);
+#endif
 }
 
 // fe_inv calculates |out| = |in|^{-1}
@@ -1524,7 +1540,11 @@ static char get_bit(const uint8_t *in, int i) {
   if (i < 0 || i >= 256) {
     return 0;
   }
+#ifdef OPENSSL_BIGENDIAN
+  return (in[(i >> 3) ^ (sizeof(BN_ULONG)-1)] >> (i & 7)) & 1;
+#else
   return (in[i >> 3] >> (i & 7)) & 1;
+#endif
 }
 
 // Interleaved point multiplication using precomputed point multiples: The
