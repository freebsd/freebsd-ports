--- src/lib/crypto.c.orig	2010-05-20 20:15:22.000000000 +0300
+++ src/lib/crypto.c	2010-05-20 20:16:39.000000000 +0300
@@ -316,7 +316,11 @@
  */
 static ASN1_OCTET_STRING *openssl_cert_keyid(X509 *cert) {
    X509_EXTENSION *ext;
+#if (OPENSSL_VERSION_NUMBER < 0x10000000L)
    const X509V3_EXT_METHOD *method;
+#else
+   const X509V3_EXT_METHOD *method;
+#endif
    ASN1_OCTET_STRING *keyid;
    int i;
 #if (OPENSSL_VERSION_NUMBER >= 0x0090800FL)
@@ -980,6 +984,10 @@
    free (sig);
 }
 
+#if OPENSSL_VERSION_NUMBER >= 0x10000000L
+#define EVP_PKEY_decrypt EVP_PKEY_decrypt_old
+#define EVP_PKEY_encrypt EVP_PKEY_encrypt_old
+#endif
 /*
  * Create a new encryption session.
  *  Returns: A pointer to a CRYPTO_SESSION object on success.
