--- server/util_pcre.c.orig	2005-11-10 16:20:05.000000000 +0100
+++ server/util_pcre.c	2012-02-13 23:11:17.898984171 +0100
@@ -137,7 +137,8 @@
 
 if (preg->re_pcre == NULL) return AP_REG_INVARG;
 
-preg->re_nsub = pcre_info((const pcre *)preg->re_pcre, NULL, NULL);
+pcre_fullinfo((const pcre *)preg->re_pcre, NULL,
+               PCRE_INFO_CAPTURECOUNT, &(preg->re_nsub));
 return 0;
 }
 
