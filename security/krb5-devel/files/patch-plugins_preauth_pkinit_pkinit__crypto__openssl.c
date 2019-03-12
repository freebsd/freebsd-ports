--- plugins/preauth/pkinit/pkinit_crypto_openssl.c.orig	2018-11-01 23:51:07 UTC
+++ plugins/preauth/pkinit/pkinit_crypto_openssl.c
@@ -188,7 +188,8 @@ pkinit_pkcs11_code_to_text(int err);
     (*_x509_pp) = PKCS7_cert_from_signer_info(_p7,_si)
 #endif
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if (defined(OPENSSL_VERSION_NUMBER) && OPENSSL_VERSION_NUMBER < 0x10100000L) || \
+     defined(LIBRESSL_VERSION_NUMBER)
 
 /* 1.1 standardizes constructor and destructor names, renaming
  * EVP_MD_CTX_{create,destroy} and deprecating ASN1_STRING_data. */
@@ -3040,7 +3041,9 @@ cleanup:
     return retval;
 }
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if ((defined(OPENSSL_VERSION_NUMBER) && OPENSSL_VERSION_NUMBER >= 0x10100000L) && \
+     !defined(LIBRESSL_VERSION_NUMBER)) || \
+     (defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER >= 0x20900000L)
 
 /*
  * We need to decode DomainParameters from RFC 3279 section 2.3.3.  We would
