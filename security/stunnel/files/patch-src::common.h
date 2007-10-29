--- src/common.h.old	2007-10-29 17:56:21.000000000 +0200
+++ src/common.h	2007-10-29 18:07:22.000000000 +0200
@@ -314,9 +314,6 @@
 
 #define OPENSSL_THREAD_DEFINES
 #include <openssl/opensslconf.h>
-#if !defined(OPENSSL_THREADS) && defined(USE_PTHREAD)
-#error OpenSSL library compiled without thread support
-#endif /* !OPENSSL_THREADS && USE_PTHREAD */
 
 #include <openssl/lhash.h>
 #include <openssl/ssl.h>
