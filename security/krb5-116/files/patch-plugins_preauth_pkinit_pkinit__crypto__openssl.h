--- plugins/preauth/pkinit/pkinit_crypto_openssl.h.orig	2016-12-01 22:31:25 UTC
+++ plugins/preauth/pkinit/pkinit_crypto_openssl.h
@@ -46,7 +46,7 @@
 #include <openssl/asn1.h>
 #include <openssl/pem.h>
 
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(OPENSSL_VERSION_NUMBER)
 #include <openssl/asn1t.h>
 #else
 #include <openssl/asn1_mac.h>
