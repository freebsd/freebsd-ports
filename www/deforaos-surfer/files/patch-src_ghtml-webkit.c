--- src/ghtml-webkit.c.orig	2016-02-07 03:44:23 UTC
+++ src/ghtml-webkit.c
@@ -20,6 +20,9 @@
 #include <string.h>
 #include <errno.h>
 #include <netdb.h>
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
 #include <arpa/inet.h>
 #include <libintl.h>
 #include <webkit/webkit.h>
@@ -205,7 +208,7 @@ static void _new_init(GHtml * ghtml)
 	{
 		"/etc/pki/tls/certs/ca-bundle.crt",
 		"/etc/ssl/certs/ca-certificates.crt",
-		"/etc/openssl/certs/ca-certificates.crt",
+		"/etc/ssl/cert.pem",
 		PREFIX "/etc/ssl/certs/ca-certificates.crt",
 		PREFIX "/etc/openssl/certs/ca-certificates.crt"
 	};
