--- src/ghtml-webkit.c.orig	2015-02-03 21:41:14.728793636 +0100
+++ src/ghtml-webkit.c	2015-02-03 21:41:39.669804743 +0100
@@ -207,7 +207,8 @@
 		"/etc/ssl/certs/ca-certificates.crt",
 		"/etc/openssl/certs/ca-certificates.crt",
 		PREFIX "/etc/ssl/certs/ca-certificates.crt",
-		PREFIX "/etc/openssl/certs/ca-certificates.crt"
+		PREFIX "/etc/openssl/certs/ca-certificates.crt",
+		PREFIX "/share/certs/ca-root-nss.crt"
 	};
 	size_t i;
 #endif
