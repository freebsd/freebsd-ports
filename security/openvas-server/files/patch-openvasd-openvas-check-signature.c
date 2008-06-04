--- openvasd/openvas-check-signature.c.orig	2008-04-27 00:56:59.000000000 +0900
+++ openvasd/openvas-check-signature.c	2008-04-27 00:57:55.000000000 +0900
@@ -43,7 +43,7 @@
 #include <includes.h>
 #include <gnutls/gnutls.h>
 #include <gnutls/x509.h>
-
+#include <getopt.h>
 
 void
 print_tls_error(char *txt, int err)
