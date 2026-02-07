--- src/pehash.c.orig	2018-10-20 11:44:18 UTC
+++ src/pehash.c
@@ -215,13 +215,25 @@ static void calc_hash(const char *alg_name, const unsi
 	unsigned char md_value[EVP_MAX_MD_SIZE];
 	unsigned int md_len;
 
-	EVP_MD_CTX md_ctx;
+	// See https://wiki.openssl.org/index.php/1.1_API_Changes
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
+	EVP_MD_CTX md_ctx_auto;
+	EVP_MD_CTX *md_ctx = &md_ctx_auto;
+#else
+	EVP_MD_CTX *md_ctx = EVP_MD_CTX_new();
+#endif
+
 	// FIXME: Handle errors - Check return values.
-	EVP_MD_CTX_init(&md_ctx);
-	EVP_DigestInit_ex(&md_ctx, md, NULL);
-	EVP_DigestUpdate(&md_ctx, data, size);
-	EVP_DigestFinal_ex(&md_ctx, md_value, &md_len);
-	EVP_MD_CTX_cleanup(&md_ctx);
+	EVP_MD_CTX_init(md_ctx);
+	EVP_DigestInit_ex(md_ctx, md, NULL);
+	EVP_DigestUpdate(md_ctx, data, size);
+	EVP_DigestFinal_ex(md_ctx, md_value, &md_len);
+
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
+	EVP_MD_CTX_cleanup(md_ctx);
+#else
+	EVP_MD_CTX_free(md_ctx);
+#endif
 
 	for (unsigned int i=0; i < md_len; i++)
 		sprintf(&output[i * 2], "%02x", md_value[i]);
