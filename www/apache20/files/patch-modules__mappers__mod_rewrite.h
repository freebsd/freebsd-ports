--- ./modules/mappers/mod_rewrite.h.orig	2006-07-12 07:40:55.000000000 +0000
+++ ./modules/mappers/mod_rewrite.h	2010-10-21 05:40:53.667623114 +0000
@@ -199,14 +199,14 @@
 typedef struct {
     char    *input;                /* Input string of RewriteCond */
     char    *pattern;              /* the RegExp pattern string */
-    regex_t *regexp;
+    ap_regex_t *regexp;
     int      flags;                /* Flags which control the match */
 } rewritecond_entry;
 
 typedef struct {
     apr_array_header_t *rewriteconds;    /* the corresponding RewriteCond entries */
     char    *pattern;              /* the RegExp pattern string */
-    regex_t *regexp;               /* the RegExp pattern compilation */
+    ap_regex_t *regexp;               /* the RegExp pattern compilation */
     char    *output;               /* the Substitution string */
     int      flags;                /* Flags which control the substitution */
     char    *forced_mimetype;      /* forced MIME type of substitution */
@@ -290,7 +290,7 @@
 typedef struct backrefinfo {
     char *source;
     int nsub;
-    regmatch_t regmatch[AP_MAX_REG_MATCH];
+    ap_regmatch_t regmatch[AP_MAX_REG_MATCH];
 } backrefinfo;
 
 
