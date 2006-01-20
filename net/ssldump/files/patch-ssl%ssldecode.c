--- sssl/ssldecode.c.orig	Sat Aug 17 05:33:17 2002
+++ ssl/ssldecode.c	Fri Jan 20 13:09:49 2006
@@ -50,6 +50,7 @@
 #ifdef OPENSSL
 #include <openssl/ssl.h>
 #include <openssl/hmac.h>
+#include <openssl/md5.h>
 #include <openssl/evp.h>
 #include <openssl/x509v3.h>
 #endif
