--- src/mbedtls.h.orig	2016-09-27 06:06:29 UTC
+++ src/mbedtls.h
@@ -27,12 +27,21 @@
 
 #define LIBSSH2_RSA             1
 #define LIBSSH2_DSA             0
+#define LIBSSH2_ECDSA           0
 
 #define MD5_DIGEST_LENGTH      16
 #define SHA_DIGEST_LENGTH      20
 #define SHA256_DIGEST_LENGTH   32
+#define SHA384_DIGEST_LENGTH   48
 #define SHA512_DIGEST_LENGTH   64
 
+#define EC_MAX_POINT_LEN ((528 * 2 / 8) + 1)
+
+#if LIBSSH2_ECDSA
+#else
+#define _libssh2_ec_key void
+#endif
+
 /*******************************************************************/
 /*
  * mbedTLS backend: Global context handles
@@ -80,6 +89,8 @@ mbedtls_ctr_drbg_context _libssh2_mbedtl
   _libssh2_mbedtls_hash_init(pctx, MBEDTLS_MD_RIPEMD160, key, keylen)
 #define libssh2_hmac_sha256_init(pctx, key, keylen) \
   _libssh2_mbedtls_hash_init(pctx, MBEDTLS_MD_SHA256, key, keylen)
+#define libssh2_hmac_sha384_init(pctx, key, keylen) \
+  _libssh2_mbedtls_hash_init(pctx, MBEDTLS_MD_SHA384, key, keylen)
 #define libssh2_hmac_sha512_init(pctx, key, keylen) \
   _libssh2_mbedtls_hash_init(pctx, MBEDTLS_MD_SHA512, key, keylen)
 
@@ -119,6 +130,23 @@ mbedtls_ctr_drbg_context _libssh2_mbedtl
 
 /*******************************************************************/
 /*
+ * mbedTLS backend: SHA384 functions
+ */
+
+#define libssh2_sha384_ctx      mbedtls_md_context_t
+
+#define libssh2_sha384_init(pctx) \
+  _libssh2_mbedtls_hash_init(pctx, MBEDTLS_MD_SHA384, NULL, 0)
+#define libssh2_sha384_update(ctx, data, datalen) \
+  mbedtls_md_update(&ctx, (unsigned char *) data, datalen)
+#define libssh2_sha384_final(ctx, hash) \
+  _libssh2_mbedtls_hash_final(&ctx, hash)
+#define libssh2_sha384(data, datalen, hash) \
+  _libssh2_mbedtls_hash(data, datalen, MBEDTLS_MD_SHA384, hash)
+
+
+/*******************************************************************/
+/*
  * mbedTLS backend: SHA512 functions
  */
 
