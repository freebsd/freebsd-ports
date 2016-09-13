--- vncstorepw/ultravnc_dsm_helper.c.orig	2010-04-23 04:29:43 UTC
+++ vncstorepw/ultravnc_dsm_helper.c
@@ -413,8 +413,10 @@ void enc_do(char *ciph, char *keyfile, c
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
