--- libsylph/ssl.c.orig	Mon Dec 18 15:16:01 2006
+++ libsylph/ssl.c	Sat Dec 23 14:41:18 2006
@@ -55,6 +55,7 @@
 	if (certs_dir) {
 		LOOK_FOR("ca-certificates.crt");
 		LOOK_FOR("ca-bundle.crt");
+		LOOK_FOR("ca-root.crt");
 		LOOK_FOR("certs.crt");
 	}
 
