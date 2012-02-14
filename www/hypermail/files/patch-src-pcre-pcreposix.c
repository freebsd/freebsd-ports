--- src/pcre/pcreposix.c.orig	2003-07-03 20:04:06.000000000 +0200
+++ src/pcre/pcreposix.c	2012-02-14 12:49:55.077985140 +0100
@@ -217,7 +217,8 @@
 
 if (preg->re_pcre == NULL) return pcre_posix_error_code(errorptr);
 
-preg->re_nsub = pcre_info(preg->re_pcre, NULL, NULL);
+pcre_fullinfo((const pcre *)preg->re_pcre, NULL,
+               PCRE_INFO_CAPTURECOUNT, &(preg->re_nsub));
 return 0;
 }
 
