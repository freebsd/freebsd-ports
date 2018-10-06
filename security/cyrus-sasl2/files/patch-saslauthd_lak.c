--- saslauthd/lak.c.orig	2012-10-12 14:05:48 UTC
+++ saslauthd/lak.c
@@ -53,6 +53,46 @@
 #endif
 #include <openssl/evp.h>
 #include <openssl/des.h>
+
+/* for legacy libcrypto support */
+#include "crypto-compat.h"
+
+#if defined(HAVE_OPENSSL) && (OPENSSL_VERSION_NUMBER < 0x10100000L)
+
+#include <openssl/engine.h>
+
+static void *OPENSSL_zalloc(size_t num)
+{
+    void *ret = OPENSSL_malloc(num);
+
+    if (ret != NULL)
+        memset(ret, 0, num);
+    return ret;
+}
+
+EVP_MD_CTX *EVP_MD_CTX_new(void)
+{
+    return OPENSSL_zalloc(sizeof(EVP_MD_CTX));
+}
+
+void EVP_MD_CTX_free(EVP_MD_CTX *ctx)
+{
+    EVP_MD_CTX_cleanup(ctx);
+    OPENSSL_free(ctx);
+}
+
+EVP_ENCODE_CTX *EVP_ENCODE_CTX_new(void)
+{
+    return OPENSSL_zalloc(sizeof(EVP_ENCODE_CTX));
+}
+
+void EVP_ENCODE_CTX_free(EVP_ENCODE_CTX *ctx)
+{
+    OPENSSL_free(ctx);
+}
+
+#endif /* HAVE_OPENSSL && OPENSSL_VERSION_NUMBER */
+
 #endif
 
 #define LDAP_DEPRECATED 1
@@ -1715,20 +1755,28 @@ static int lak_base64_decode(
 
 	int rc, i, tlen = 0;
 	char *text;
-	EVP_ENCODE_CTX EVP_ctx;
+	EVP_ENCODE_CTX *enc_ctx = EVP_ENCODE_CTX_new();
+
+	if (enc_ctx == NULL)
+		return LAK_NOMEM;
 
 	text = (char *)malloc(((strlen(src)+3)/4 * 3) + 1);
-	if (text == NULL)
+	if (text == NULL) {
+		EVP_ENCODE_CTX_free(enc_ctx);
 		return LAK_NOMEM;
+	}
 
-	EVP_DecodeInit(&EVP_ctx);
-	rc = EVP_DecodeUpdate(&EVP_ctx, text, &i, (char *)src, strlen(src));
+	EVP_DecodeInit(enc_ctx);
+	rc = EVP_DecodeUpdate(enc_ctx, (unsigned char *) text, &i, (const unsigned char *)src, strlen(src));
 	if (rc < 0) {
+		EVP_ENCODE_CTX_free(enc_ctx);
 		free(text);
 		return LAK_FAIL;
 	}
 	tlen += i;
-	EVP_DecodeFinal(&EVP_ctx, text, &i); 
+	EVP_DecodeFinal(enc_ctx, (unsigned char *) text, &i);
+
+	EVP_ENCODE_CTX_free(enc_ctx);
 
 	*ret = text;
 	if (rlen != NULL)
@@ -1744,7 +1792,7 @@ static int lak_check_hashed(
 {
 	int rc, clen;
 	LAK_HASH_ROCK *hrock = (LAK_HASH_ROCK *) rock;
-	EVP_MD_CTX mdctx;
+	EVP_MD_CTX *mdctx;
 	const EVP_MD *md;
 	unsigned char digest[EVP_MAX_MD_SIZE];
 	char *cred;
@@ -1753,17 +1801,24 @@ static int lak_check_hashed(
 	if (!md)
 		return LAK_FAIL;
 
+	mdctx = EVP_MD_CTX_new();
+	if (!mdctx)
+		return LAK_NOMEM;
+
 	rc = lak_base64_decode(hash, &cred, &clen);
-	if (rc != LAK_OK)
+	if (rc != LAK_OK) {
+		EVP_MD_CTX_free(mdctx);
 		return rc;
+	}
 
-	EVP_DigestInit(&mdctx, md);
-	EVP_DigestUpdate(&mdctx, passwd, strlen(passwd));
+	EVP_DigestInit(mdctx, md);
+	EVP_DigestUpdate(mdctx, passwd, strlen(passwd));
 	if (hrock->salted) {
-		EVP_DigestUpdate(&mdctx, &cred[EVP_MD_size(md)],
+		EVP_DigestUpdate(mdctx, &cred[EVP_MD_size(md)],
 				 clen - EVP_MD_size(md));
 	}
-	EVP_DigestFinal(&mdctx, digest, NULL);
+	EVP_DigestFinal(mdctx, digest, NULL);
+	EVP_MD_CTX_free(mdctx);
 
 	rc = memcmp((char *)cred, (char *)digest, EVP_MD_size(md));
 	free(cred);
