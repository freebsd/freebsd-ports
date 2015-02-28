--- lib/tls_mosq.h.orig	2014-10-08 23:50:07.000000000 +0200
+++ lib/tls_mosq.h	2015-02-27 22:21:09.128116088 +0100
@@ -33,8 +33,9 @@
 #ifdef WITH_TLS
 
 #include <openssl/ssl.h>
+#include <sys/socket.h>
 #ifdef WITH_TLS_PSK
-#  if OPENSSL_VERSION_NUMBER >= 0x10000000
+#  if OPENSSL_VERSION_NUMBER >= 0x10000000 && !defined(LIBRESSL_VERSION_NUMBER)
 #    define REAL_WITH_TLS_PSK
 #  else
 #    warning "TLS-PSK not supported, openssl too old."
