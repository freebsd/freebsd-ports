--- src/cgi_ssl.c.orig	Thu Nov 20 01:00:59 2003
+++ src/cgi_ssl.c	Thu Nov 20 01:01:17 2003
@@ -19,7 +19,7 @@
  */
 
 #include "boa.h"
-#include <gnutls/x509.h>
+#include <gnutls/gnutls.h>
 
 #ifdef ENABLE_SSL
 extern int ssl_verify;
