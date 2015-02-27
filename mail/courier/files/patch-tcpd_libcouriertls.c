--- tcpd/libcouriertls.c.orig	2009-11-21 21:07:32.000000000 +0100
+++ tcpd/libcouriertls.c	2015-02-27 21:12:46.065044595 +0100
@@ -551,9 +551,7 @@
 	if (!protocol || !*protocol)
 		protocol="SSL23";
 
-	ctx=SSL_CTX_new(protocol && strcmp(protocol, "SSL2") == 0
-							? SSLv2_method():
-		protocol && strcmp(protocol, "SSL3") == 0 ? SSLv3_method():
+	ctx=SSL_CTX_new(protocol && strcmp(protocol, "SSL3") == 0 ? SSLv3_method():
 		protocol && strcmp(protocol, "SSL23") == 0 ? SSLv23_method():
 		TLSv1_method());
 
