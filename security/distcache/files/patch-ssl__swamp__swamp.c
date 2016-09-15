--- ssl/swamp/swamp.c.orig	2004-02-19 20:37:33 UTC
+++ ssl/swamp/swamp.c
@@ -104,10 +104,14 @@ static SSL_CTX *ossl_setup_ssl_ctx(const
 	switch(config->sslmeth) {
 	case SWAMP_SSLMETH_NORMAL:
 		sslmethod = SSLv23_client_method(); break;
+#ifndef OPENSSL_NO_SSL2
 	case SWAMP_SSLMETH_SSLv2:
 		sslmethod = SSLv2_client_method(); break;
+#endif
+#ifndef OPENSSL_NO_SSL3
 	case SWAMP_SSLMETH_SSLv3:
 		sslmethod = SSLv3_client_method(); break;
+#endif
 	case SWAMP_SSLMETH_TLSv1:
 		sslmethod = TLSv1_client_method(); break;
 	default:
