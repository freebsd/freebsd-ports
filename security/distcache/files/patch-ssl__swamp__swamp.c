--- ssl/swamp/swamp.c.orig	2004-02-19 15:37:33.000000000 -0500
+++ ssl/swamp/swamp.c	2015-03-23 19:47:07.787300000 -0400
@@ -104,8 +104,10 @@
 	switch(config->sslmeth) {
 	case SWAMP_SSLMETH_NORMAL:
 		sslmethod = SSLv23_client_method(); break;
+#ifndef OPENSSL_NO_SSL2
 	case SWAMP_SSLMETH_SSLv2:
 		sslmethod = SSLv2_client_method(); break;
+#endif
 	case SWAMP_SSLMETH_SSLv3:
 		sslmethod = SSLv3_client_method(); break;
 	case SWAMP_SSLMETH_TLSv1:
