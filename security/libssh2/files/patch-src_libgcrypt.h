--- src/libgcrypt.h.orig	2016-01-18 12:41:58 UTC
+++ src/libgcrypt.h
@@ -54,10 +54,15 @@
 
 #define LIBSSH2_RSA 1
 #define LIBSSH2_DSA 1
+#define LIBSSH2_ECDSA 0
 
 #define MD5_DIGEST_LENGTH 16
 #define SHA_DIGEST_LENGTH 20
 #define SHA256_DIGEST_LENGTH 32
+#define SHA384_DIGEST_LENGTH 48
+#define SHA512_DIGEST_LENGTH 64
+
+#define EC_MAX_POINT_LEN ((528 * 2 / 8) + 1)
 
 #define _libssh2_random(buf, len)                \
   (gcry_randomize ((buf), (len), GCRY_STRONG_RANDOM), 1)
@@ -87,6 +92,28 @@
 #define libssh2_sha256(message, len, out) \
   gcry_md_hash_buffer (GCRY_MD_SHA256, out, message, len)
 
+#define libssh2_sha384_ctx gcry_md_hd_t
+
+#define libssh2_sha384_init(ctx) \
+  (GPG_ERR_NO_ERROR == gcry_md_open (ctx,  GCRY_MD_SHA384, 0))
+#define libssh2_sha384_update(ctx, data, len) \
+  gcry_md_write (ctx, (unsigned char *) data, len)
+#define libssh2_sha384_final(ctx, out) \
+  memcpy (out, gcry_md_read (ctx, 0), SHA384_DIGEST_LENGTH), gcry_md_close (ctx)
+#define libssh2_sha384(message, len, out) \
+  gcry_md_hash_buffer (GCRY_MD_SHA384, out, message, len)
+
+#define libssh2_sha512_ctx gcry_md_hd_t
+
+#define libssh2_sha512_init(ctx) \
+  (GPG_ERR_NO_ERROR == gcry_md_open (ctx,  GCRY_MD_SHA512, 0))
+#define libssh2_sha512_update(ctx, data, len) \
+  gcry_md_write (ctx, (unsigned char *) data, len)
+#define libssh2_sha512_final(ctx, out) \
+  memcpy (out, gcry_md_read (ctx, 0), SHA512_DIGEST_LENGTH), gcry_md_close (ctx)
+#define libssh2_sha512(message, len, out) \
+  gcry_md_hash_buffer (GCRY_MD_SHA512, out, message, len)
+
 #define libssh2_md5_ctx gcry_md_hd_t
 
 /* returns 0 in case of failure */
@@ -135,6 +162,11 @@
 
 #define _libssh2_dsa_free(dsactx)  gcry_sexp_release (dsactx)
 
+#if LIBSSH2_ECDSA
+#else
+#define _libssh2_ec_key void
+#endif
+
 #define _libssh2_cipher_type(name) int name
 #define _libssh2_cipher_ctx gcry_cipher_hd_t
 
