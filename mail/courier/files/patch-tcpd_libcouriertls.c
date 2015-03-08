--- tcpd/libcouriertls.c.orig	2009-11-21 21:07:32.000000000 +0100
+++ tcpd/libcouriertls.c	2015-03-07 22:46:47.521076321 +0100
@@ -551,9 +551,13 @@
 	if (!protocol || !*protocol)
 		protocol="SSL23";
 
-	ctx=SSL_CTX_new(protocol && strcmp(protocol, "SSL2") == 0
-							? SSLv2_method():
+	ctx=SSL_CTX_new(
+#ifndef OPENSSL_NO_SSL2
+		protocol && strcmp(protocol, "SSL2") == 0 ? SSLv2_method():
+#endif
+#ifndef OPENSSL_NO_SSL3
 		protocol && strcmp(protocol, "SSL3") == 0 ? SSLv3_method():
+#endif
 		protocol && strcmp(protocol, "SSL23") == 0 ? SSLv23_method():
 		TLSv1_method());
 
