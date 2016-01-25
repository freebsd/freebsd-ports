--- libsylph/ssl.c.orig	2016-01-25 16:00:23 UTC
+++ libsylph/ssl.c
@@ -59,6 +59,7 @@ static gchar *find_certs_file(const gcha
 		LOOK_FOR("ca-bundle.crt");
 		LOOK_FOR("ca-root.crt");
 		LOOK_FOR("certs.crt");
+		LOOK_FOR("cert.pem");
 	}
 
 #undef LOOK_FOR
