--- libsylph/ssl.c.orig	2014-06-10 06:06:36.000000000 +0200
+++ libsylph/ssl.c	2015-02-16 16:38:30.082429979 +0100
@@ -59,6 +59,7 @@
 		LOOK_FOR("ca-bundle.crt");
 		LOOK_FOR("ca-root.crt");
 		LOOK_FOR("certs.crt");
+		LOOK_FOR("cert.pem");
 	}
 
 #undef LOOK_FOR
@@ -117,7 +118,7 @@
 			certs_dir = NULL;
 		}
 #else
-		certs_file = find_certs_file("/etc/ssl");
+		certs_file = find_certs_file("/usr/local/etc/ssl");
 		if (!certs_file)
 			certs_file = find_certs_file("/etc");
 #endif
