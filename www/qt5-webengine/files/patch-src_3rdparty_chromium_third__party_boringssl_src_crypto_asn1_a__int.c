--- src/3rdparty/chromium/third_party/boringssl/src/crypto/asn1/a_int.c.orig	2019-05-23 12:39:34 UTC
+++ src/3rdparty/chromium/third_party/boringssl/src/crypto/asn1/a_int.c
@@ -369,7 +369,9 @@ int ASN1_INTEGER_set_uint64(ASN1_INTEGER *out, uint64_
 
     OPENSSL_free(out->data);
     out->data = newdata;
+#ifndef OPENSSL_BIGENDIAN
     v = CRYPTO_bswap8(v);
+#endif
     memcpy(out->data, &v, sizeof(v));
 
     out->type = V_ASN1_INTEGER;
