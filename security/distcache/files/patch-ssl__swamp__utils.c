--- ssl/swamp/utils.c.orig	2004-04-30 12:58:00 UTC
+++ ssl/swamp/utils.c
@@ -267,10 +267,14 @@ int util_parse_sslmeth(const char *str_toconvert, swam
 {
 	if(!strcmp(str_toconvert, "normal"))
 		*val = SWAMP_SSLMETH_NORMAL;
+#if OPENSSL_VERSION_NUMBER < 0x10100000L && !defined(OPENSSL_NO_SSL2)
 	else if(!strcmp(str_toconvert, "sslv2"))
 		*val = SWAMP_SSLMETH_SSLv2;
+#endif
+#ifndef OPENSSL_NO_SSL3
 	else if(!strcmp(str_toconvert, "sslv3"))
 		*val = SWAMP_SSLMETH_SSLv3;
+#endif
 	else if(!strcmp(str_toconvert, "tlsv1"))
 		*val = SWAMP_SSLMETH_TLSv1;
 	else
