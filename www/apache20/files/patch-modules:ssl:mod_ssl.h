--- modules/ssl/mod_ssl.h.orig	Tue Sep 16 01:00:06 2003
+++ modules/ssl/mod_ssl.h	Sat Jan 10 22:08:18 2004
@@ -123,7 +123,7 @@
 #else /* !HAVE_SSLC (implicit HAVE_OPENSSL) */
 
 #include <ssl.h>
-#include <err.h>
+#include <openssl/err.h>
 #include <x509.h>
 #include <pem.h>
 #include <crypto.h>
