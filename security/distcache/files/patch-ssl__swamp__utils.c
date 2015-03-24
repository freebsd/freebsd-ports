--- ssl/swamp/utils.c.orig	2004-02-17 15:29:34.000000000 -0500
+++ ssl/swamp/utils.c	2015-03-23 19:47:34.795067000 -0400
@@ -269,8 +269,10 @@
 {
 	if(!strcmp(str_toconvert, "normal"))
 		*val = SWAMP_SSLMETH_NORMAL;
+#ifndef OPENSSL_NO_SSL2
 	else if(!strcmp(str_toconvert, "sslv2"))
 		*val = SWAMP_SSLMETH_SSLv2;
+#endif
 	else if(!strcmp(str_toconvert, "sslv3"))
 		*val = SWAMP_SSLMETH_SSLv3;
 	else if(!strcmp(str_toconvert, "tlsv1"))
