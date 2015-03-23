--- tcpd/libcouriertls.c.orig	2009-11-21 15:07:32.000000000 -0500
+++ tcpd/libcouriertls.c	2015-03-23 18:04:57.776710000 -0400
@@ -551,8 +551,10 @@
 	if (!protocol || !*protocol)
 		protocol="SSL23";
 
-	ctx=SSL_CTX_new(protocol && strcmp(protocol, "SSL2") == 0
-							? SSLv2_method():
+	ctx=SSL_CTX_new(
+#ifndef OPENSSL_NO_SSL2
+		protocol && strcmp(protocol, "SSL2") == 0 ? SSLv2_method():
+#endif
 		protocol && strcmp(protocol, "SSL3") == 0 ? SSLv3_method():
 		protocol && strcmp(protocol, "SSL23") == 0 ? SSLv23_method():
 		TLSv1_method());
