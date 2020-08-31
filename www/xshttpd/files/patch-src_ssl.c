--- src/ssl.c.orig	2009-01-10 22:52:29 UTC
+++ src/ssl.c
@@ -244,7 +244,11 @@ sslverify_callback(int preverify_ok, X509_STORE_CTX *x
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
