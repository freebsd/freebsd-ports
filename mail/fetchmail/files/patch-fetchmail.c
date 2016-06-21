--- fetchmail.c.orig	2013-04-23 20:00:45 UTC
+++ fetchmail.c
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
@@ -263,6 +267,12 @@ int main(int argc, char **argv)
 #ifdef SSL_ENABLE
 	"+SSL"
 #endif
+#ifdef OPENSSL_NO_SSL2
+	"-SSLv2"
+#endif
+#ifdef OPENSSL_NO_SSL3_METHOD
+	"-SSLv3"
+#endif
 #ifdef OPIE_ENABLE
 	"+OPIE"
 #endif /* OPIE_ENABLE */
