--- src/openssl/openssl_compat.h.orig	2017-09-12 13:21:09 UTC
+++ src/openssl/openssl_compat.h
@@ -49,4 +49,19 @@
 
 #endif /* !defined(XMLSEC_OPENSSL_API_110) */
 
+/******************************************************************************
+ *
+ * LibreSSL 2.7+ compatibility (implements most of OpenSSL 1.1 API)
+ *
+ *****************************************************************************/
+#if defined(XMLSEC_OPENSSL_API_110) && defined(LIBRESSL_VERSION_NUMBER) 
+/* EVP_CIPHER_CTX stuff */
+#define EVP_CIPHER_CTX_encrypting(x)       ((x)->encrypt)
+
+/* X509 stuff */
+#define X509_STORE_CTX_get_by_subject      X509_STORE_get_by_subject
+#define X509_OBJECT_new()                  (calloc(1, sizeof(X509_OBJECT)))
+#define X509_OBJECT_free(x) { X509_OBJECT_free_contents(x); free(x); }
+#endif
+
 #endif /* __XMLSEC_OPENSSL_OPENSSL_COMPAT_H__ */
