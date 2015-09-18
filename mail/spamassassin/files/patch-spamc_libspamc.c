$OpenBSD: patch-spamc_libspamc_c,v 1.3 2015/05/23 14:18:55 bluhm Exp $
--- spamc/libspamc.c.orig	Tue Apr 28 21:56:59 2015
+++ spamc/libspamc.c	Wed May 20 19:53:07 2015
@@ -1216,7 +1216,7 @@ int message_filter(struct transport *tp, const char *u
 	if (flags & SPAMC_TLSV1) {
 	    meth = TLSv1_client_method();
 	} else {
-	    meth = SSLv3_client_method(); /* default */
+	    meth = SSLv23_client_method(); /* default */
 	}
 	SSL_load_error_strings();
 	ctx = SSL_CTX_new(meth);
@@ -1604,7 +1604,7 @@ int message_tell(struct transport *tp, const char *use
     if (flags & SPAMC_USE_SSL) {
 #ifdef SPAMC_SSL
 	SSLeay_add_ssl_algorithms();
-	meth = SSLv3_client_method();
+	meth = SSLv23_client_method();
 	SSL_load_error_strings();
 	ctx = SSL_CTX_new(meth);
 #else
