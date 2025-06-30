--- examples/nettle-openssl.c.orig	2025-06-26 18:29:03 UTC
+++ examples/nettle-openssl.c
@@ -291,6 +291,7 @@ openssl_hash_update(void *p,
   EVP_DigestUpdate(ctx->evp, src, length);
 }
 
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
 #define OPENSSL_HASH(NAME, name)					\
 static void								\
 openssl_##name##_init(void *p)						\
@@ -321,6 +322,38 @@ nettle_openssl_##name = {						\
   openssl_hash_update,							\
   openssl_##name##_digest						\
 };
+#else
+#define OPENSSL_HASH(NAME, name)					\
+static void								\
+openssl_##name##_init(void *p)						\
+{									\
+  struct openssl_hash_ctx *ctx = p;					\
+  if ((ctx->evp = EVP_MD_CTX_create()) == NULL)			\
+    return;								\
+									\
+  EVP_DigestInit(ctx->evp, EVP_##name());				\
+}									\
+									\
+static void								\
+openssl_##name##_digest(void *p,					\
+		    size_t length, uint8_t *dst)			\
+{									\
+  struct openssl_hash_ctx *ctx = p;					\
+  assert(length == NAME##_DIGEST_LENGTH);				\
+									\
+  EVP_DigestFinal(ctx->evp, dst, NULL);					\
+  EVP_DigestInit(ctx->evp, EVP_##name());				\
+}									\
+									\
+const struct nettle_hash						\
+nettle_openssl_##name = {						\
+  "openssl " #name, sizeof(struct openssl_hash_ctx),			\
+  NAME##_DIGEST_LENGTH, NAME##_CBLOCK,					\
+  openssl_##name##_init,						\
+  openssl_hash_update,							\
+  openssl_##name##_digest						\
+};
+#endif
 
 OPENSSL_HASH(MD5, md5)
 OPENSSL_HASH(SHA1, sha1)
