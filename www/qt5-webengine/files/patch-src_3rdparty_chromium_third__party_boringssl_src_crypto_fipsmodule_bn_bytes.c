--- src/3rdparty/chromium/third_party/boringssl/src/crypto/fipsmodule/bn/bytes.c.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/third_party/boringssl/src/crypto/fipsmodule/bn/bytes.c
@@ -136,9 +136,13 @@ BIGNUM *BN_le2bn(const uint8_t *in, size_t len, BIGNUM
   // Make sure the top bytes will be zeroed.
   ret->d[num_words - 1] = 0;
 
-  // We only support little-endian platforms, so we can simply memcpy the
-  // internal representation.
+#ifdef OPENSSL_BIGENDIAN
+  uint8_t *out = (uint8_t *)ret->d;
+  for (size_t i = 0; i < len; i++)
+    out[i ^ (BN_BYTES-1)] = in[i];
+#else
   OPENSSL_memcpy(ret->d, in, len);
+#endif
   return ret;
 }
 
@@ -157,7 +161,11 @@ size_t BN_bn2bin(const BIGNUM *in, uint8_t *out) {
 static int fits_in_bytes(const uint8_t *bytes, size_t num_bytes, size_t len) {
   uint8_t mask = 0;
   for (size_t i = len; i < num_bytes; i++) {
+#ifdef OPENSSL_BIGENDIAN
+    mask |= bytes[i ^ (BN_BYTES-1)];
+#else
     mask |= bytes[i];
+#endif
   }
   return mask == 0;
 }
@@ -172,9 +180,13 @@ int BN_bn2le_padded(uint8_t *out, size_t len, const BI
     num_bytes = len;
   }
 
-  // We only support little-endian platforms, so we can simply memcpy into the
-  // internal representation.
+#ifdef OPENSSL_BIGENDIAN
+  for (size_t i = 0; i < num_bytes; i++) {
+    out[i] = bytes[i ^ (BN_BYTES-1)];
+  }
+#else
   OPENSSL_memcpy(out, bytes, num_bytes);
+#endif
   // Pad out the rest of the buffer with zeroes.
   OPENSSL_memset(out + num_bytes, 0, len - num_bytes);
   return 1;
@@ -190,11 +202,15 @@ int BN_bn2bin_padded(uint8_t *out, size_t len, const B
     num_bytes = len;
   }
 
-  // We only support little-endian platforms, so we can simply write the buffer
-  // in reverse.
+#ifdef OPENSSL_BIGENDIAN
   for (size_t i = 0; i < num_bytes; i++) {
+    out[len - i - 1] = bytes[i ^ (BN_BYTES-1)];
+  }
+#else
+  for (size_t i = 0; i < num_bytes; i++) {
     out[len - i - 1] = bytes[i];
   }
+#endif
   // Pad out the rest of the buffer with zeroes.
   OPENSSL_memset(out, 0, len - num_bytes);
   return 1;
