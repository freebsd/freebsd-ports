--- pound.h.orig	Wed Jul 23 04:48:13 2003
+++ pound.h	Wed Jul 23 04:48:49 2003
@@ -163,10 +163,6 @@
 #define OPENSSL_THREAD_DEFINES
 #include    <openssl/ssl.h>
 #if OPENSSL_VERSION_NUMBER >= 0x00907000L
-#ifndef OPENSSL_THREADS
-#error  "Pound requires OpenSSL with thread support"
-#endif
-#else
 #ifndef THREADS
 #error  "Pound requires OpenSSL with thread support"
 #endif
