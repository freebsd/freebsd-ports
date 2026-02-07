--- ptstream.c.orig	2020-05-07 15:17:41 UTC
+++ ptstream.c
@@ -20,6 +20,7 @@
 /* ptstream.c */
 
 #include <arpa/inet.h>
+#include <netinet/in.h>
 #include <openssl/x509v3.h>
 #include <stdio.h>
 #include <stdlib.h>
