--- plugins/preauth/pkinit/pkinit_crypto_openssl.c.orig	2015-02-24 23:19:36.000000000 +0100
+++ plugins/preauth/pkinit/pkinit_crypto_openssl.c	2015-02-28 22:10:11.277738117 +0100
@@ -173,7 +173,7 @@
 pkinit_pkcs11_code_to_text(int err);
 
 
-#if OPENSSL_VERSION_NUMBER >= 0x10000000L
+#if OPENSSL_VERSION_NUMBER >= 0x10000000L && !defined(OPENSSL_NO_CMS)
 /* Use CMS support present in OpenSSL 1.0 and later. */
 #include <openssl/cms.h>
 #define pkinit_CMS_get0_content_signed(_cms) CMS_get0_content(_cms)
