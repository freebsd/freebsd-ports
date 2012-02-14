--- libs/thirdparty/pcre/pcreposix.c.orig	2012-02-14 11:08:58.826982602 +0100
+++ libs/thirdparty/pcre/pcreposix.c	2012-02-14 11:09:36.105982836 +0100
@@ -238,7 +238,8 @@
 
 if (preg->re_pcre == NULL) return eint[errorcode];
 
-preg->re_nsub = pcre_info((const pcre *)preg->re_pcre, NULL, NULL);
+pcre_fullinfo((const pcre *)preg->re_pcre, NULL,
+               PCRE_INFO_CAPTURECOUNT, &(preg->re_nsub));
 return 0;
 }
 
