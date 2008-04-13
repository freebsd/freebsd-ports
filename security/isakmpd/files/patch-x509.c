--- x509.c.orig	2004-08-11 03:21:01.000000000 +0800
+++ x509.c	2008-04-13 21:00:05.000000000 +0800
@@ -910,7 +910,13 @@
 	X509_STORE_CTX_init(&csc, x509_cas, cert, NULL);
 #if OPENSSL_VERSION_NUMBER >= 0x00907000L
 	/* XXX See comment in x509_read_crls_from_dir.  */
-	if (x509_cas->flags & X509_V_FLAG_CRL_CHECK) {
+	if (
+#if OPENSSL_VERSION_NUMBER >= 0x00908020L
+	    x509_cas->param->flags
+#else
+	    x509_cas->flags
+#endif
+	                    & X509_V_FLAG_CRL_CHECK) {
 		X509_STORE_CTX_set_flags(&csc, X509_V_FLAG_CRL_CHECK);
 		X509_STORE_CTX_set_flags(&csc, X509_V_FLAG_CRL_CHECK_ALL);
 	}
