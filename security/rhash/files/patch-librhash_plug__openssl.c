--- librhash/plug_openssl.c.orig	2019-12-14 16:52:11 UTC
+++ librhash/plug_openssl.c
@@ -18,10 +18,15 @@
 #include <string.h>
 #include <assert.h>
 #include <openssl/opensslconf.h>
-#include <openssl/md4.h>
 #include <openssl/md5.h>
 #include <openssl/sha.h>
 
+#ifndef OPENSSL_NO_MD4
+#  include <openssl/md4.h>
+#  define PLUGIN_MD4 RHASH_MD4
+#else
+#  define PLUGIN_MD4 0
+#endif
 #ifndef OPENSSL_NO_RIPEMD
 #  include <openssl/ripemd.h>
 #  define PLUGIN_RIPEMD160 RHASH_RIPEMD160
@@ -48,7 +53,7 @@
 
 #define OPENSSL_DEFAULT_HASH_MASK (RHASH_MD5 | RHASH_SHA1 | \
 	RHASH_SHA224 | RHASH_SHA256 | RHASH_SHA384 | RHASH_SHA512)
-#define PLUGIN_SUPPORTED_HASH_MASK (RHASH_MD4 | RHASH_MD5 | RHASH_SHA1 | \
+#define PLUGIN_SUPPORTED_HASH_MASK (PLUGIN_MD4 | RHASH_MD5 | RHASH_SHA1 | \
 	RHASH_SHA224 | RHASH_SHA256 | RHASH_SHA384 | RHASH_SHA512 | \
 	PLUGIN_RIPEMD160 | PLUGIN_WHIRLPOOL)
 
@@ -89,7 +94,9 @@ OS_METHOD(WHIRLPOOL);
 		CALL_FINAL(name, result, (CTX_TYPE*)ctx); \
 	}
 
+#ifndef OPENSSL_NO_MD4
 WRAP_FINAL(MD4)
+#endif
 WRAP_FINAL(MD5)
 WRAP_FINAL2(SHA1, SHA_CTX)
 WRAP_FINAL2(SHA224, SHA256_CTX)
@@ -114,7 +121,11 @@ rhash_info info_sslwhpl = { RHASH_WHIRLPOOL, 0, 64, "W
 
 /* The table of supported OpenSSL hash functions */
 rhash_hash_info rhash_openssl_methods[] = {
+#ifndef OPENSSL_NO_MD4
 	{ &info_md4, sizeof(MD4_CTX), offsetof(MD4_CTX, A), HASH_INFO_METHODS(MD4) }, /* 128 bit */
+#else
+	{ 0, 0, 0, 0, 0, 0, 0},
+#endif
 	{ &info_md5, sizeof(MD5_CTX), offsetof(MD5_CTX, A), HASH_INFO_METHODS(MD5) }, /* 128 bit */
 	{ &info_sha1, sizeof(SHA_CTX), offsetof(SHA_CTX, h0),  HASH_INFO_METHODS(SHA1) }, /* 160 bit */
 	{ &info_sha224, sizeof(SHA256_CTX), offsetof(SHA256_CTX, h), HASH_INFO_METHODS(SHA224) }, /* 224 bit */
@@ -187,7 +198,9 @@ static int load_openssl_runtime(void)
 
 	if (handle == NULL) return 0; /* could not load OpenSSL */
 
+#ifndef OPENSSL_NO_MD4
 	LOAD_ADDR(0, MD4)
+#endif
 	LOAD_ADDR(1, MD5);
 	LOAD_ADDR(2, SHA1);
 	LOAD_ADDR(3, SHA224);
