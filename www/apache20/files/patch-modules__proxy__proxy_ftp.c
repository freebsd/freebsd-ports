--- ./modules/proxy/proxy_ftp.c.orig	2010-05-13 19:18:50.000000000 +0000
+++ ./modules/proxy/proxy_ftp.c	2010-10-21 05:40:53.660623887 +0000
@@ -426,11 +426,11 @@
         int found = 0;
         int eos = 0;
 
-        regex_t *re = NULL;
-        regmatch_t re_result[LS_REG_MATCH];
+        ap_regex_t *re = NULL;
+        ap_regmatch_t re_result[LS_REG_MATCH];
 
         /* Compile the output format of "ls -s1" as a fallback for non-unix ftp listings */
-        re = ap_pregcomp(p, LS_REG_PATTERN, REG_EXTENDED);
+        re = ap_pregcomp(p, LS_REG_PATTERN, AP_REG_EXTENDED);
         ap_assert(re != NULL);
 
         /* get a complete line */
