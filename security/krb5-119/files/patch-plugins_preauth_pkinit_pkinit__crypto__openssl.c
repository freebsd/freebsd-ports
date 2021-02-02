--- plugins/preauth/pkinit/pkinit_crypto_openssl.c.orig	2019-01-08 08:02:37.000000000 -0800
+++ plugins/preauth/pkinit/pkinit_crypto_openssl.c	2019-05-02 12:18:53.494194000 -0700
@@ -189,7 +189,8 @@
     (*_x509_pp) = PKCS7_cert_from_signer_info(_p7,_si)
 #endif
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if (defined(OPENSSL_VERSION_NUMBER) && OPENSSL_VERSION_NUMBER < 0x10100000L) || \
+     defined(LIBRESSL_VERSION_NUMBER)
 
 /* 1.1 standardizes constructor and destructor names, renaming
  * EVP_MD_CTX_{create,destroy} and deprecating ASN1_STRING_data. */
@@ -249,6 +250,10 @@
 
 #endif
 
+#if defined(LIBRESSL_VERSION_NUMBER) && !defined(static_ASN1_SEQUENCE_END_name)
+#define static_ASN1_SEQUENCE_END_name	ASN1_SEQUENCE_END_name
+#endif
+
 static struct pkcs11_errstrings {
     short code;
     char *text;
@@ -3053,7 +3058,9 @@
     return retval;
 }
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if ((defined(OPENSSL_VERSION_NUMBER) && OPENSSL_VERSION_NUMBER >= 0x10100000L) && \
+     !defined(LIBRESSL_VERSION_NUMBER)) || \
+     (defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER >= 0x20900000L)
 
 /*
  * We need to decode DomainParameters from RFC 3279 section 2.3.3.  We would
