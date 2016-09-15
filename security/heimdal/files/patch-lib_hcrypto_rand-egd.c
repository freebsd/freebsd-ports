--- lib/hcrypto/rand-egd.c.orig	2012-12-09 22:06:44 UTC
+++ lib/hcrypto/rand-egd.c
@@ -54,6 +54,7 @@ static const char *egd_path = "/var/run/
 
 #define MAX_EGD_DATA 255
 
+#ifndef OPENSSL_NO_EGD
 static int
 connect_egd(const char *path)
 {
@@ -258,3 +259,5 @@ RAND_egd_bytes(const char *filename, int
 
     return 1;
 }
+
+#endif
