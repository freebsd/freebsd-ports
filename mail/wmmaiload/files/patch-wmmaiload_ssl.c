--- wmmaiload/ssl.c.orig	2005-07-30 13:52:55 UTC
+++ wmmaiload/ssl.c
@@ -23,6 +23,8 @@
  *
  */
 
+#include <string.h>
+
 #include "config.h"
 
 #ifdef HAVE_SSL
@@ -39,7 +41,7 @@ static SSL_CTX *init_CTX(void)
 
         OpenSSL_add_all_algorithms();
 
-        method = SSLv2_client_method();
+        method = SSLv23_client_method();
         ctx = SSL_CTX_new(method);
         return ctx;
 }
