--- crypto_openssl.old.c	2004-04-09 22:25:56.000000000 +0530
+++ crypto_openssl.c	2004-08-02 20:30:03.000000000 +0530
@@ -1654,6 +1654,7 @@
 
 	HMAC_Final((HMAC_CTX *)c, res->v, &l);
 	res->l = l;
+	HMAC_cleanup((HMAC_CTX *)c);
 	(void)racoon_free(c);
 
 	if (SHA512_DIGEST_LENGTH != res->l) {
@@ -1710,6 +1711,7 @@
 
 	HMAC_Final((HMAC_CTX *)c, res->v, &l);
 	res->l = l;
+	HMAC_cleanup((HMAC_CTX *)c);
 	(void)racoon_free(c);
 
 	if (SHA384_DIGEST_LENGTH != res->l) {
@@ -1766,6 +1768,7 @@
 
 	HMAC_Final((HMAC_CTX *)c, res->v, &l);
 	res->l = l;
+	HMAC_cleanup((HMAC_CTX *)c);
 	(void)racoon_free(c);
 
 	if (SHA256_DIGEST_LENGTH != res->l) {
@@ -1823,6 +1826,7 @@
 
 	HMAC_Final((HMAC_CTX *)c, res->v, &l);
 	res->l = l;
+	HMAC_cleanup((HMAC_CTX *)c);
 	(void)racoon_free(c);
 
 	if (SHA_DIGEST_LENGTH != res->l) {
@@ -1879,6 +1883,7 @@
 
 	HMAC_Final((HMAC_CTX *)c, res->v, &l);
 	res->l = l;
+	HMAC_cleanup((HMAC_CTX *)c);
 	(void)racoon_free(c);
 
 	if (MD5_DIGEST_LENGTH != res->l) {
