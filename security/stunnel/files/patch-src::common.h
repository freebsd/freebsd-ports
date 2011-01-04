Description: Build with older OpenSSL and enable transparent binding.
Forwarded: yes (the transparent proxying part)
Author: Peter Pentchev <roam@FreeBSD.org>,
	Jason Helfman <jhelfman@experts-exchange.com>
Last-Update: 2011-01-04

--- src/common.h.orig
+++ src/common.h
@@ -337,6 +337,15 @@
 /* old kernel headers without IP_TRANSPARENT definition */
 #define IP_TRANSPARENT 19
 #endif /* IP_TRANSPARENT */
+#define STUNNEL_TRANSPARENT IP_TRANSPARENT
+#define STUNNEL_TRANSPARENT_NAME "IP_TRANSPARENT"
+#define STUNNEL_TRANSPARENT_LEVEL SOL_IP
+#else /* __linux__ */
+#ifdef IP_BINDANY
+#define STUNNEL_TRANSPARENT IP_BINDANY
+#define STUNNEL_TRANSPARENT_NAME "IP_BINDANY"
+#define STUNNEL_TRANSPARENT_LEVEL IPPROTO_IP
+#endif
 #endif /* __linux__ */
 
 #endif /* USE_WIN32 */
@@ -347,9 +356,6 @@
 
 #define OPENSSL_THREAD_DEFINES
 #include <openssl/opensslconf.h>
-#if !defined(OPENSSL_THREADS) && defined(USE_PTHREAD)
-#error OpenSSL library compiled without thread support
-#endif /* !OPENSSL_THREADS && USE_PTHREAD */
 
 #include <openssl/lhash.h>
 #include <openssl/ssl.h>
