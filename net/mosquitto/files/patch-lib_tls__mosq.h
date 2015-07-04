--- lib/tls_mosq.h.orig	2015-05-07 13:21:22 UTC
+++ lib/tls_mosq.h
@@ -20,8 +20,9 @@ Contributors:
 #ifdef WITH_TLS
 
 #include <openssl/ssl.h>
+#include <sys/socket.h>
 #ifdef WITH_TLS_PSK
-#  if OPENSSL_VERSION_NUMBER >= 0x10000000
+#  if OPENSSL_VERSION_NUMBER >= 0x10000000 && !defined(OPENSSL_NO_PSK)
 #    define REAL_WITH_TLS_PSK
 #  else
 #    warning "TLS-PSK not supported, openssl too old."
