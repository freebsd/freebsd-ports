--- re/re-tre.c.orig	Mon Jul 12 14:33:52 2004
+++ re/re-tre.c	Mon Jul 12 14:36:05 2004
@@ -117,6 +117,7 @@
 static int re_exec(RE *re, char *string) {
   regaparams_t regparams ;
   regamatch_t regamatch = {0,};
+  int ret;
 
   memcpy(&regparams, re->hint, sizeof(regaparams_t));
 
@@ -131,16 +132,17 @@
   regparams.max_err=1;
 #endif
 
-  int ret = tre_regaexec(re->code, string, &regamatch, regparams, 0);
+  ret = tre_regaexec(re->code, string, &regamatch, regparams, 0);
   return ret!=0;
 }
 
 char *re_tre_params(RE *re, char *s) {
+  int *counter;
+  int end = 0;
   regaparams_t *params = malloc(sizeof(regaparams_t));
   tre_regaparams_default(params);
-  int *counter = &params->max_err;
+  counter = &params->max_err;
   *counter = 1;
-  int end = 0;
   printf("s=%s\n", s);
   while(*s && !end) {
     if (*s>='0' && *s<='9') {
