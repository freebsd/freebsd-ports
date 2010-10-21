--- ./modules/mappers/mod_rewrite.c.orig	2006-07-27 17:07:21.000000000 +0000
+++ ./modules/mappers/mod_rewrite.c	2010-10-21 05:40:53.666621309 +0000
@@ -552,7 +552,7 @@
     char *str = apr_pstrdup(cmd->pool, in_str);
     rewrite_server_conf *sconf;
     rewritecond_entry *newcond;
-    regex_t *regexp;
+    ap_regex_t *regexp;
     char *a1;
     char *a2;
     char *a3;
@@ -602,11 +602,11 @@
        we can compile the pattern for case insensitive matching,
        under the old V8 library we have to do it self via a hack */
     if (newcond->flags & CONDFLAG_NOCASE) {
-        rc = ((regexp = ap_pregcomp(cmd->pool, cp, REG_EXTENDED|REG_ICASE))
+        rc = ((regexp = ap_pregcomp(cmd->pool, cp, AP_REG_EXTENDED|AP_REG_ICASE))
               == NULL);
     }
     else {
-        rc = ((regexp = ap_pregcomp(cmd->pool, cp, REG_EXTENDED)) == NULL);
+        rc = ((regexp = ap_pregcomp(cmd->pool, cp, AP_REG_EXTENDED)) == NULL);
     }
     if (rc) {
         return apr_pstrcat(cmd->pool,
@@ -697,7 +697,7 @@
     char *str = apr_pstrdup(cmd->pool, in_str);
     rewrite_server_conf *sconf;
     rewriterule_entry *newrule;
-    regex_t *regexp;
+    ap_regex_t *regexp;
     char *a1;
     char *a2;
     char *a3;
@@ -743,9 +743,9 @@
         newrule->flags |= RULEFLAG_NOTMATCH;
         cp++;
     }
-    mode = REG_EXTENDED;
+    mode = AP_REG_EXTENDED;
     if (newrule->flags & RULEFLAG_NOCASE) {
-        mode |= REG_ICASE;
+        mode |= AP_REG_ICASE;
     }
     if ((regexp = ap_pregcomp(cmd->pool, cp, mode)) == NULL) {
         return apr_pstrcat(cmd->pool,
@@ -1945,8 +1945,8 @@
     char *output;
     const char *vary;
     char newuri[MAX_STRING_LEN];
-    regex_t *regexp;
-    regmatch_t regmatch[AP_MAX_REG_MATCH];
+    ap_regex_t *regexp;
+    ap_regmatch_t regmatch[AP_MAX_REG_MATCH];
     backrefinfo *briRR = NULL;
     backrefinfo *briRC = NULL;
     int failed;
@@ -2303,7 +2303,7 @@
     char input[MAX_STRING_LEN];
     apr_finfo_t sb;
     request_rec *rsub;
-    regmatch_t regmatch[AP_MAX_REG_MATCH];
+    ap_regmatch_t regmatch[AP_MAX_REG_MATCH];
     int rc;
 
     /*
