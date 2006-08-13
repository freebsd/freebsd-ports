
$FreeBSD$

--- pound.h.orig
+++ pound.h
@@ -178,7 +178,8 @@
 #if HAVE_OPENSSL_SSL_H
 #define OPENSSL_THREAD_DEFINES
 #include    <openssl/ssl.h>
-#if OPENSSL_VERSION_NUMBER >= 0x00907000L
+#include    <openssl/opensslconf.h>
+#if OPENSSL_VERSION_NUMBER > 0x0090705FL
 #ifndef OPENSSL_THREADS
 #error  "Pound requires OpenSSL with thread support"
 #endif
