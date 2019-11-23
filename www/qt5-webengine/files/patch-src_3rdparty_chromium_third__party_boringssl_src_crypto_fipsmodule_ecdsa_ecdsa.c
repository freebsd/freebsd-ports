--- src/3rdparty/chromium/third_party/boringssl/src/crypto/fipsmodule/ecdsa/ecdsa.c.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/third_party/boringssl/src/crypto/fipsmodule/ecdsa/ecdsa.c
@@ -80,7 +80,11 @@ static void digest_to_scalar(const EC_GROUP *group, EC
   }
   OPENSSL_memset(out, 0, sizeof(EC_SCALAR));
   for (size_t i = 0; i < digest_len; i++) {
+#ifdef OPENSSL_BIGENDIAN
+    out->bytes[i ^ (BN_BYTES-1)] = digest[digest_len - 1 - i];
+#else
     out->bytes[i] = digest[digest_len - 1 - i];
+#endif
   }
 
   // If it is still too long, truncate remaining bits with a shift.
