--- include/ssl_private.h.orig	2024-02-04 19:32:52 UTC
+++ include/ssl_private.h
@@ -46,9 +46,6 @@
 #include <openssl/x509v3.h>
 #include <openssl/dh.h>
 #include <openssl/bn.h>
-#ifndef LIBRESSL_VERSION_NUMBER
-#include <openssl/provider.h>
-#endif
 /* Avoid tripping over an engine build installed globally and detected
  * when the user points at an explicit non-engine flavor of OpenSSL
  */
