--- ./lib/x509/rfc2818_hostname.c.orig	2014-07-24 14:38:24.963183389 -0500
+++ ./lib/x509/rfc2818_hostname.c	2014-07-24 14:38:55.151183492 -0500
@@ -25,6 +25,7 @@
 #include <common.h>
 #include <gnutls_errors.h>
 #include <arpa/inet.h>
+#include <netinet/in.h>
 
 static int
 check_ip(gnutls_x509_crt_t cert, const void *ip, unsigned ip_size)
