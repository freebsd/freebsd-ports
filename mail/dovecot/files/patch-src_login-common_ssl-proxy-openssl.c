--- src/login-common/ssl-proxy-openssl.c.orig	2015-03-07 13:25:36.487131678 +0100
+++ src/login-common/ssl-proxy-openssl.c	2015-03-07 13:24:28.303136938 +0100
@@ -21,6 +21,7 @@
 #include <openssl/ssl.h>
 #include <openssl/err.h>
 #include <openssl/rand.h>
+#include <openssl/comp.h>
 
 #define DOVECOT_SSL_DEFAULT_CIPHER_LIST "ALL:!LOW:!SSLv2"
 /* Check every 30 minutes if parameters file has been updated */
