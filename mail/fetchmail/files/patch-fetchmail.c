--- fetchmail.c.orig	2018-12-30 11:43:19.032822000 -0600
+++ fetchmail.c	2018-12-30 12:51:55.552234000 -0600
@@ -50,6 +50,10 @@
 #include <arpa/nameser.h>
 #include <resolv.h>
 
+#ifdef SSL_ENABLE
+#include <openssl/ssl.h>
+#endif
+
 #ifndef ENETUNREACH
 #define ENETUNREACH   128       /* Interactive doesn't know this */
 #endif /* ENETUNREACH */
@@ -263,10 +267,10 @@
 #ifdef SSL_ENABLE
 	"+SSL"
 #endif
-#if HAVE_DECL_SSLV2_CLIENT_METHOD + 0 == 0
+#if (HAVE_DECL_SSLV2_CLIENT_METHOD + 0 == 0) && !defined(OPENSSL_NO_SSL2)
  	"-SSLv2"
 #endif
-#if HAVE_DECL_SSLV3_CLIENT_METHOD + 0 == 0
+#if (HAVE_DECL_SSLV3_CLIENT_METHOD + 0 == 0) && !defined(OPENSSL_NO_SSL3_METHOD)
  	"-SSLv3"
 #endif
 #ifdef OPIE_ENABLE
