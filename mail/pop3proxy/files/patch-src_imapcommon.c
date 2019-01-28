--- src/imapcommon.c.orig	2005-02-01 15:21:28 UTC
+++ src/imapcommon.c
@@ -295,16 +295,24 @@ extern ICD_Struct *Get_Server_conn( char *Username, 
     int rc;
     unsigned int Expiration;
 
-    EVP_MD_CTX mdctx;
+    EVP_MD_CTX *mdctx;
     int md_len;
 
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
+    EVP_MD_CTX mdctx_;
+#define EVP_MD_CTX_new(x) &mdctx_
+#define EVP_MD_CTX_free(x)
+#endif
+
     Expiration = PC_Struct.cache_expiration_time;
     memset( &Server, 0, sizeof Server );
     
     /* need to md5 the passwd regardless, so do that now */
-    EVP_DigestInit(&mdctx, EVP_md5());
-    EVP_DigestUpdate(&mdctx, Password, strlen(Password));
-    EVP_DigestFinal(&mdctx, md5pw, &md_len);
+    mdctx = EVP_MD_CTX_new();
+    EVP_DigestInit(mdctx, EVP_md5());
+    EVP_DigestUpdate(mdctx, Password, strlen(Password));
+    EVP_DigestFinal(mdctx, md5pw, &md_len);
+    EVP_MD_CTX_free(mdctx);
     
     /* see if we have a reusable connection available */
     ICC_Active = NULL;
