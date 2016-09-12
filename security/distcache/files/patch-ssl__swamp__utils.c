--- ssl/swamp/utils.c.orig	2004-02-17 20:29:34 UTC
+++ ssl/swamp/utils.c
@@ -269,10 +269,14 @@ int util_parse_sslmeth(const char *str_t
 {
 	if(!strcmp(str_toconvert, "normal"))
 		*val = SWAMP_SSLMETH_NORMAL;
+#ifndef OPENSSL_NO_SSL2
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
