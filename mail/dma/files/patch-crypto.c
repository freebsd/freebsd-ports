--- crypto.c.orig	2021-02-11 13:53:38 UTC
+++ crypto.c
@@ -78,7 +78,7 @@ init_cert_file(SSL_CTX *ctx, const char *path)
 	return (0);
 }
 
-int
+static int
 verify_server_fingerprint(const X509 *cert)
 {
 	unsigned char fingerprint[EVP_MAX_MD_SIZE] = {0};
