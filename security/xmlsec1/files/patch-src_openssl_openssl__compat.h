--- src/openssl/openssl_compat.h.orig	2022-05-03 14:36:17 UTC
+++ src/openssl/openssl_compat.h
@@ -51,6 +51,21 @@
 
 /******************************************************************************
  *
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
+/******************************************************************************
+ *
  * boringssl compatibility
  *
  *****************************************************************************/
