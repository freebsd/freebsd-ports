--- src/ghtml-webkit.c.orig	2022-11-15 01:17:05 UTC
+++ src/ghtml-webkit.c
@@ -22,6 +22,9 @@
 #include <errno.h>
 #include <sys/socket.h>
 #include <netdb.h>
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
 #include <arpa/inet.h>
 #include <libintl.h>
 #include <webkit/webkit.h>
@@ -207,7 +210,7 @@ static void _new_init(GHtml * ghtml)
 	{
 		"/etc/pki/tls/certs/ca-bundle.crt",
 		"/etc/ssl/certs/ca-certificates.crt",
-		"/etc/openssl/certs/ca-certificates.crt",
+		"/etc/ssl/cert.pem",
 		PREFIX "/etc/ssl/certs/ca-certificates.crt",
 		PREFIX "/etc/openssl/certs/ca-certificates.crt"
 	};
