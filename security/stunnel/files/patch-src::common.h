Description: Build on FreeBSD versions of OpenSSL < 0.9.8b.
Forwarded: not-needed
Author: Peter Pentchev <roam@FreeBSD.org>
Last-Update: 2010-09-20

--- src/common.h.orig
+++ src/common.h
@@ -347,9 +347,6 @@
 
 #define OPENSSL_THREAD_DEFINES
 #include <openssl/opensslconf.h>
-#if !defined(OPENSSL_THREADS) && defined(USE_PTHREAD)
-#error OpenSSL library compiled without thread support
-#endif /* !OPENSSL_THREADS && USE_PTHREAD */
 
 #include <openssl/lhash.h>
 #include <openssl/ssl.h>
