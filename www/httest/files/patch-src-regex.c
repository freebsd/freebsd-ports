--- src/regex.c.orig	2012-02-14 10:50:10.169982096 +0100
+++ src/regex.c	2012-02-14 10:51:09.360982595 +0100
@@ -88,7 +88,8 @@
   if (preg->re_pcre == NULL)
     return NULL;
 
-  preg->re_nsub = pcre_info((const pcre *) preg->re_pcre, NULL, NULL);
+  pcre_fullinfo((const pcre *)preg->re_pcre, NULL,
+                 PCRE_INFO_CAPTURECOUNT, &(preg->re_nsub));
 
   apr_pool_cleanup_register(p, (void *) preg, regex_cleanup,
                             apr_pool_cleanup_null);
