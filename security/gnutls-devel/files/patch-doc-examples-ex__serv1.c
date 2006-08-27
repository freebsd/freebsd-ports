--- doc/examples/ex-serv1.c.orig	Sat Aug 26 20:48:22 2006
+++ doc/examples/ex-serv1.c	Sat Aug 26 20:49:55 2006
@@ -10,6 +10,7 @@
 #include <arpa/inet.h>
 #include <string.h>
 #include <unistd.h>
+#include <netinet/in.h>
 #include <gnutls/gnutls.h>
 
 #define KEYFILE "key.pem"
