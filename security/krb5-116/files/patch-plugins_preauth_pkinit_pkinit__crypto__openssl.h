--- plugins/preauth/pkinit/pkinit_crypto_openssl.h.orig	2018-05-03 07:34:47.000000000 -0700
+++ plugins/preauth/pkinit/pkinit_crypto_openssl.h	2018-06-12 18:35:23.603366000 -0700
@@ -46,7 +46,8 @@
 #include <openssl/asn1.h>
 #include <openssl/pem.h>
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if (defined(OPENSSL_VERSION_NUMBER) && OPENSSL_VERSION_NUMBER >= 0x10100000L) && \
+     !defined(LIBRESSL_VERSION_NUMBER)
 #include <openssl/asn1t.h>
 #else
 #include <openssl/asn1_mac.h>
