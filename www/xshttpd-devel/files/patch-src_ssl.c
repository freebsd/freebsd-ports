--- src/ssl.c.orig	2015-09-05 20:50:21 UTC
+++ src/ssl.c
@@ -538,7 +538,11 @@ sslverify_callback(int preverify_ok, X509_STORE_CTX *x
 	X509_NAME	*xsname;
 	char		*strname;
 	int		rc, ovector[OVSIZE];
+# if OPENSSL_VERSION_NUMBER < 0x10100005L
 	X509		*xs = x509_ctx->cert;
+# else
+	X509		*xs = X509_STORE_CTX_get0_cert(x509_ctx);
+# endif
 
 	/* match subject */
 	if (cursock->sslpcresdn)
@@ -937,11 +941,12 @@ loadssl(struct socket_config * const lsock, struct ssl
 			unsigned char	sign[EVP_PKEY_size(evpkey)];
 			unsigned int	siglen = 0;
 
-			EVP_MD_CTX mdctx;
-			EVP_MD_CTX_init(&mdctx);
-			EVP_SignInit(&mdctx, EVP_sha384());
-			EVP_SignUpdate(&mdctx, ticketkey, strlen(ticketkey));
-			EVP_SignFinal(&mdctx, sign, &siglen, evpkey);
+			EVP_MD_CTX *mdctx;
+			mdctx = EVP_MD_CTX_create();
+			EVP_SignInit(mdctx, EVP_sha384());
+			EVP_SignUpdate(mdctx, ticketkey, strlen(ticketkey));
+			EVP_SignFinal(mdctx, sign, &siglen, evpkey);
+			EVP_MD_CTX_destroy(mdctx);
 
 			/* The first 48 bytes are used:
 			 * - 16 bytes ticket key name
