--- lib/http.c.orig	Thu May 19 16:37:26 2005
+++ lib/http.c	Thu May 19 16:38:42 2005
@@ -19,6 +19,7 @@
 #include <string.h>
 #include <openssl/err.h>
 #include <arpa/inet.h>
+#include <netinet/in.h>
 
 /*
  * parse the url given in the second argument and fill in the h member
