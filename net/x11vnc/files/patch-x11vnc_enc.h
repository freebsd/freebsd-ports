--- x11vnc/enc.h.orig	2011-08-10 22:31:32 UTC
+++ x11vnc/enc.h
@@ -454,8 +454,10 @@ extern void enc_do(char *ciph, char *key
 		p++;
 		if (strstr(p, "md5+") == p) {
 			Digest = EVP_md5();        p += strlen("md5+");
+#ifndef OPENSSL_NO_SHA0
 		} else if (strstr(p, "sha+") == p) {
 			Digest = EVP_sha();        p += strlen("sha+");
+#endif
 		} else if (strstr(p, "sha1+") == p) {
 			Digest = EVP_sha1();       p += strlen("sha1+");
 		} else if (strstr(p, "ripe+") == p) {
