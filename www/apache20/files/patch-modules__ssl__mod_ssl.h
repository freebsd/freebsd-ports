--- ./modules/ssl/mod_ssl.h.orig	2007-05-08 19:08:47.000000000 -0400
+++ ./modules/ssl/mod_ssl.h	2010-05-06 16:06:03.737831861 -0400
@@ -90,7 +90,7 @@
 #else /* !HAVE_SSLC (implicit HAVE_OPENSSL) */
 
 #include <ssl.h>
-#include <err.h>
+#include <openssl/err.h>
 #include <x509.h>
 #include <pem.h>
 #include <crypto.h>
