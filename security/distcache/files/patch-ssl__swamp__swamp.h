--- ssl/swamp/swamp.h.orig	2004-02-17 15:29:34.000000000 -0500
+++ ssl/swamp/swamp.h	2015-03-23 19:47:20.490894000 -0400
@@ -161,7 +161,9 @@
 
 typedef enum st_swamp_sslmeth {
 	SWAMP_SSLMETH_NORMAL,	/* SSLv23_client_method() */
+#ifndef OPENSSL_NO_SSL2
 	SWAMP_SSLMETH_SSLv2,	/* SSLv2_client_method() */
+#endif
 	SWAMP_SSLMETH_SSLv3,	/* SSLv3_client_method() */
 	SWAMP_SSLMETH_TLSv1	/* TLSv1_client_method() */
 } swamp_sslmeth;
