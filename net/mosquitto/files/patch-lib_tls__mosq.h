--- lib/tls_mosq.h.orig	2017-07-10 22:46:01 UTC
+++ lib/tls_mosq.h
@@ -26,8 +26,9 @@ Contributors:
 #ifdef WITH_TLS
 
 #include <openssl/ssl.h>
+#include <sys/socket.h>
 #ifdef WITH_TLS_PSK
-#  if OPENSSL_VERSION_NUMBER >= 0x10000000
+#  if OPENSSL_VERSION_NUMBER >= 0x10000000 && !defined(OPENSSL_NO_PSK)
 #    define REAL_WITH_TLS_PSK
 #  else
 #    warning "TLS-PSK not supported, openssl too old."
