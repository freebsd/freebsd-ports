--- plugins/preauth/pkinit/pkinit_crypto_openssl.c.orig	2021-11-05 16:24:07.000000000 -0700
+++ plugins/preauth/pkinit/pkinit_crypto_openssl.c	2021-11-08 10:10:45.431325000 -0800
@@ -178,7 +178,8 @@
     (*_x509_pp) = PKCS7_cert_from_signer_info(_p7,_si)
 #endif
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if (defined(OPENSSL_VERSION_NUMBER) && OPENSSL_VERSION_NUMBER < 0x10100000L) || \
+     defined(LIBRESSL_VERSION_NUMBER)
 
 /* 1.1 standardizes constructor and destructor names, renaming
  * EVP_MD_CTX_{create,destroy} and deprecating ASN1_STRING_data. */
@@ -722,6 +723,10 @@
     DH_free(dh);
     return pkey;
 }
+
+#if defined(LIBRESSL_VERSION_NUMBER) && !defined(static_ASN1_SEQUENCE_END_name)
+#define static_ASN1_SEQUENCE_END_name	ASN1_SEQUENCE_END_name
+#endif
 
 static struct pkcs11_errstrings {
     short code;
