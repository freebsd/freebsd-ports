--- lib/tls_mosq.h.orig	2014-10-08 21:50:07 UTC
+++ lib/tls_mosq.h
@@ -33,8 +33,9 @@ POSSIBILITY OF SUCH DAMAGE.
 #ifdef WITH_TLS
 
 #include <openssl/ssl.h>
+#include <sys/socket.h>
 #ifdef WITH_TLS_PSK
-#  if OPENSSL_VERSION_NUMBER >= 0x10000000
+#  if OPENSSL_VERSION_NUMBER >= 0x10000000 && !defined(OPENSSL_NO_PSK)
 #    define REAL_WITH_TLS_PSK
 #  else
 #    warning "TLS-PSK not supported, openssl too old."
