--- ssl/swamp/swamp.h.orig	2004-04-30 12:58:00 UTC
+++ ssl/swamp/swamp.h
@@ -162,8 +162,12 @@ char *util_parse_escaped_string(const char *str_toconv
 
 typedef enum st_swamp_sslmeth {
 	SWAMP_SSLMETH_NORMAL,	/* SSLv23_client_method() */
+#if OPENSSL_VERSION_NUMBER < 0x10100000L && !defined(OPENSSL_NO_SSL2)
 	SWAMP_SSLMETH_SSLv2,	/* SSLv2_client_method() */
+#endif
+#ifndef OPENSSL_NO_SSL3_METHOD
 	SWAMP_SSLMETH_SSLv3,	/* SSLv3_client_method() */
+#endif
 	SWAMP_SSLMETH_TLSv1	/* TLSv1_client_method() */
 } swamp_sslmeth;
 
