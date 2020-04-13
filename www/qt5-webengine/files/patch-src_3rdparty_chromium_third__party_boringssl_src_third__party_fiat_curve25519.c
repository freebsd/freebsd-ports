--- src/3rdparty/chromium/third_party/boringssl/src/third_party/fiat/curve25519.c.orig	2019-11-27 21:12:25 UTC
+++ src/3rdparty/chromium/third_party/boringssl/src/third_party/fiat/curve25519.c
@@ -1964,9 +1964,14 @@ int ED25519_verify(const uint8_t *message, size_t mess
     UINT64_C(0x1000000000000000),
   };
   for (size_t i = 3;; i--) {
-    if (scopy.u64[i] > kOrder[i]) {
+#ifdef OPENSSL_BIGENDIAN
+    const uint64_t n = CRYPTO_bswap8(scopy.u64[i]);
+#else
+    const uint64_t n = scopy.u64[i];
+#endif
+    if (n > kOrder[i]) {
       return 0;
-    } else if (scopy.u64[i] < kOrder[i]) {
+    } else if (n < kOrder[i]) {
       break;
     } else if (i == 0) {
       return 0;
