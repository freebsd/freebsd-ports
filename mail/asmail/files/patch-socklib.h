--- socklib.h.orig	Wed Feb 28 03:19:38 2007
+++ socklib.h	Wed Apr 11 00:42:44 2007
@@ -14,8 +14,10 @@
 #define MG_SOCKLIB_H
 
 #include "config.h"
-#include <netinet/in.h>
 #include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
+#include <arpa/inet.h>
 #ifdef HAVE_OPENSSL_SSL_H
 #include <openssl/ssl.h>
 #include <openssl/bio.h>
