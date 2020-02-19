--- plugins/preauth/pkinit/pkinit_crypto_openssl.h.orig	2018-11-01 23:51:07 UTC
+++ plugins/preauth/pkinit/pkinit_crypto_openssl.h
@@ -46,7 +46,9 @@
 #include <openssl/asn1.h>
 #include <openssl/pem.h>
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if ((defined(OPENSSL_VERSION_NUMBER) && OPENSSL_VERSION_NUMBER >= 0x10100000L) && \
+     !defined(LIBRESSL_VERSION_NUMBER)) || \
+     (defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER >= 0x20900000L)
 #include <openssl/asn1t.h>
 #else
 #include <openssl/asn1_mac.h>
