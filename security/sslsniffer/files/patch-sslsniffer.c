--- sslsniffer.c.orig	2001-10-08 22:10:44 UTC
+++ sslsniffer.c
@@ -1573,14 +1573,22 @@ PrintCertificateInfo(UTL_CERT_INFO *buf, EVP_PKEY *key
     
     if (key == NULL) return;
     
-    switch (key->type) 
+    switch (EVP_PKEY_id(key))
     {
     case EVP_PKEY_RSA:
+#if OPENSSL_VERSION_NUMBER < 0x10100005L
 	buf->keysize = RSA_size(key->pkey.rsa)*8;
+#else
+	buf->keysize = RSA_size(EVP_PKEY_get0_RSA(key))*8;
+#endif
 	printf("  RSA Public key size %d bits\n\n",buf->keysize);
 	break;      
     case EVP_PKEY_DSA:
+#if OPENSSL_VERSION_NUMBER < 0x10100005L
 	buf->keysize = DSA_size(key->pkey.dsa)*8;
+#else
+	buf->keysize = DSA_size(EVP_PKEY_get0_DSA(key))*8;
+#endif
 	printf("  DSS Public key size %d bits\n\n",buf->keysize);
 	break;
     default:
