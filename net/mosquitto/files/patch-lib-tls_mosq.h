--- lib/tls_mosq.h.orig	2014-05-07 14:39:22.000000000 -0700
+++ lib/tls_mosq.h	2014-05-07 14:39:47.000000000 -0700
@@ -33,6 +33,7 @@
 #ifdef WITH_TLS
 
 #include <openssl/ssl.h>
+#include <sys/socket.h>
 #ifdef WITH_TLS_PSK
 #  if OPENSSL_VERSION_NUMBER >= 0x10000000
 #    define REAL_WITH_TLS_PSK
