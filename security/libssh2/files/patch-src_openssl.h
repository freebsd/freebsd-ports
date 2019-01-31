--- src/openssl.h.orig	2016-02-17 21:59:57 UTC
+++ src/openssl.h
@@ -70,6 +70,12 @@
 # define LIBSSH2_DSA 1
 #endif
 
+#ifdef OPENSSL_NO_ECDSA
+# define LIBSSH2_ECDSA 0
+#else
+# define LIBSSH2_ECDSA 1
+#endif
+
 #ifdef OPENSSL_NO_MD5
 # define LIBSSH2_MD5 0
 #else
@@ -117,6 +123,8 @@
 # define LIBSSH2_3DES 1
 #endif
 
+#define EC_MAX_POINT_LEN ((528 * 2 / 8) + 1)
+
 #define _libssh2_random(buf, len) RAND_bytes ((buf), (len))
 
 #define libssh2_prepare_iovec(vec, len)  /* Empty. */
@@ -168,6 +176,52 @@ int _libssh2_sha256(const unsigned char 
 #define libssh2_sha256(x,y,z) _libssh2_sha256(x,y,z)
 
 #ifdef HAVE_OPAQUE_STRUCTS
+#define libssh2_sha384_ctx EVP_MD_CTX *
+#else
+#define libssh2_sha384_ctx EVP_MD_CTX
+#endif
+
+/* returns 0 in case of failure */
+int _libssh2_sha384_init(libssh2_sha384_ctx *ctx);
+#define libssh2_sha384_init(x) _libssh2_sha384_init(x)
+#ifdef HAVE_OPAQUE_STRUCTS
+#define libssh2_sha384_update(ctx, data, len) EVP_DigestUpdate(ctx, data, len)
+#define libssh2_sha384_final(ctx, out) do { \
+                                            EVP_DigestFinal(ctx, out, NULL); \
+                                            EVP_MD_CTX_free(ctx); \
+                                       } while(0)
+#else
+#define libssh2_sha384_update(ctx, data, len) EVP_DigestUpdate(&(ctx), data, len)
+#define libssh2_sha384_final(ctx, out) EVP_DigestFinal(&(ctx), out, NULL)
+#endif
+int _libssh2_sha384(const unsigned char *message, unsigned long len,
+                    unsigned char *out);
+#define libssh2_sha384(x,y,z) _libssh2_sha384(x,y,z)
+
+#ifdef HAVE_OPAQUE_STRUCTS
+#define libssh2_sha512_ctx EVP_MD_CTX *
+#else
+#define libssh2_sha512_ctx EVP_MD_CTX
+#endif
+
+/* returns 0 in case of failure */
+int _libssh2_sha512_init(libssh2_sha512_ctx *ctx);
+#define libssh2_sha512_init(x) _libssh2_sha512_init(x)
+#ifdef HAVE_OPAQUE_STRUCTS
+#define libssh2_sha512_update(ctx, data, len) EVP_DigestUpdate(ctx, data, len)
+#define libssh2_sha512_final(ctx, out) do { \
+                                            EVP_DigestFinal(ctx, out, NULL); \
+                                            EVP_MD_CTX_free(ctx); \
+                                       } while(0)
+#else
+#define libssh2_sha512_update(ctx, data, len) EVP_DigestUpdate(&(ctx), data, len)
+#define libssh2_sha512_final(ctx, out) EVP_DigestFinal(&(ctx), out, NULL)
+#endif
+int _libssh2_sha512(const unsigned char *message, unsigned long len,
+                    unsigned char *out);
+#define libssh2_sha512(x,y,z) _libssh2_sha512(x,y,z)
+
+#ifdef HAVE_OPAQUE_STRUCTS
 #define libssh2_md5_ctx EVP_MD_CTX *
 #else
 #define libssh2_md5_ctx EVP_MD_CTX
@@ -239,9 +293,23 @@ int _libssh2_md5_init(libssh2_md5_ctx *c
 
 #define libssh2_dsa_ctx DSA
 
-
 #define _libssh2_dsa_free(dsactx) DSA_free(dsactx)
 
+#if LIBSSH2_ECDSA
+#define libssh2_ecdsa_ctx EC_KEY
+#define _libssh2_ecdsa_free(ecdsactx) EC_KEY_free(ecdsactx)
+#define _libssh2_ec_key EC_KEY
+
+typedef enum {
+    LIBSSH2_EC_CURVE_NISTP256 = NID_X9_62_prime256v1,
+    LIBSSH2_EC_CURVE_NISTP384 = NID_secp384r1,
+    LIBSSH2_EC_CURVE_NISTP521 = NID_secp521r1,
+}
+libssh2_curve_type;
+#else
+#define _libssh2_ec_key void
+#endif
+
 #define _libssh2_cipher_type(name) const EVP_CIPHER *(*name)(void)
 #ifdef HAVE_OPAQUE_STRUCTS
 #define _libssh2_cipher_ctx EVP_CIPHER_CTX *
@@ -290,4 +358,3 @@ int _libssh2_md5_init(libssh2_md5_ctx *c
 const EVP_CIPHER *_libssh2_EVP_aes_128_ctr(void);
 const EVP_CIPHER *_libssh2_EVP_aes_192_ctr(void);
 const EVP_CIPHER *_libssh2_EVP_aes_256_ctr(void);
-
