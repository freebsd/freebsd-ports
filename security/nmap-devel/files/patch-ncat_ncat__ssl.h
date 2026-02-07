--- ncat/ncat_ssl.h.orig	2022-08-25 07:51:59.000000000 -0700
+++ ncat/ncat_ssl.h	2022-09-28 08:44:14.564723000 -0700
@@ -67,7 +67,8 @@
 #include <openssl/ssl.h>
 #include <openssl/err.h>
 
 #define NCAT_CA_CERTS_FILE "ca-bundle.crt"
+#define OPENSSL_API_COMPAT	OPENSSL_VERSION_NUMBER
 
 /* OPENSSL_API_LEVEL per OpenSSL 3.0: decimal MMmmpp */
 #ifndef OPENSSL_API_LEVEL
 # if OPENSSL_API_COMPAT < 0x900000L
