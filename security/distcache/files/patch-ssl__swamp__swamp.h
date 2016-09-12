--- ssl/swamp/swamp.h.orig	2004-02-17 20:29:34 UTC
+++ ssl/swamp/swamp.h
@@ -161,7 +161,9 @@ char *util_parse_escaped_string(const ch
 
 typedef enum st_swamp_sslmeth {
 	SWAMP_SSLMETH_NORMAL,	/* SSLv23_client_method() */
+#ifndef OPENSSL_NO_SSL2
 	SWAMP_SSLMETH_SSLv2,	/* SSLv2_client_method() */
+#endif
 	SWAMP_SSLMETH_SSLv3,	/* SSLv3_client_method() */
 	SWAMP_SSLMETH_TLSv1	/* TLSv1_client_method() */
 } swamp_sslmeth;
