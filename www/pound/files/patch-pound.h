--- pound.h.orig	2008-02-11 12:53:52.000000000 +0100
+++ pound.h	2008-03-18 21:58:27.000000000 +0100
@@ -132,7 +132,8 @@
 #include    <openssl/ssl.h>
 #include    <openssl/lhash.h>
 #include    <openssl/err.h>
-#if OPENSSL_VERSION_NUMBER >= 0x00907000L
+#include    <openssl/opensslconf.h>
+#if OPENSSL_VERSION_NUMBER > 0x0090705FL
 #ifndef OPENSSL_THREADS
 #error  "Pound requires OpenSSL with thread support"
 #endif
