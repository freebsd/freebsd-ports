--- ./sslscan.c.orig	2009-09-01 14:35:59.000000000 +0200
+++ ./sslscan.c	2011-06-21 17:36:13.000000000 +0200
@@ -41,6 +41,7 @@
 #include <openssl/pkcs12.h>
 #include <openssl/x509.h>
 #include <openssl/x509v3.h>
+#include <netinet/in.h>
 
 // Defines...
 #define false 0
