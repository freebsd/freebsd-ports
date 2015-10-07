--- libsylph/ssl.c.orig	2014-06-10 04:06:36 UTC
+++ libsylph/ssl.c
@@ -59,6 +59,7 @@ static gchar *find_certs_file(const gcha
 		LOOK_FOR("ca-bundle.crt");
 		LOOK_FOR("ca-root.crt");
 		LOOK_FOR("certs.crt");
+		LOOK_FOR("cert.pem");
 	}
 
 #undef LOOK_FOR
@@ -117,7 +118,7 @@ void ssl_init(void)
 			certs_dir = NULL;
 		}
 #else
-		certs_file = find_certs_file("/etc/ssl");
+		certs_file = find_certs_file("/usr/local/etc/ssl");
 		if (!certs_file)
 			certs_file = find_certs_file("/etc");
 #endif
