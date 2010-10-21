--- ./modules/metadata/mod_setenvif.c.orig	2006-07-12 07:40:55.000000000 +0000
+++ ./modules/metadata/mod_setenvif.c	2010-10-21 05:40:53.656624209 +0000
@@ -106,9 +106,9 @@
 };
 typedef struct {
     char *name;                 /* header name */
-    regex_t *pnamereg;          /* compiled header name regex */
+    ap_regex_t *pnamereg;       /* compiled header name regex */
     char *regex;                /* regex to match against */
-    regex_t *preg;              /* compiled regex */
+    ap_regex_t *preg;           /* compiled regex */
     const apr_strmatch_pattern *pattern; /* non-regex pattern to match */
     apr_table_t *features;      /* env vars to set (or unset) */
     enum special special_type;  /* is it a "special" header ? */
@@ -159,7 +159,7 @@
 }
 
 /*
- * any non-NULL magic constant will do... used to indicate if REG_ICASE should
+ * any non-NULL magic constant will do... used to indicate if AP_REG_ICASE should
  * be used
  */
 #define ICASE_MAGIC	((void *)(&setenvif_module))
@@ -171,8 +171,8 @@
      *    -,_,[A-Z\, [a-z] and [0-9].
      * assume the header name is a regular expression.
      */
-    regex_t *preg = ap_pregcomp(p, "^[-A-Za-z0-9_]*$",
-                                (REG_EXTENDED | REG_NOSUB ));
+    ap_regex_t *preg = ap_pregcomp(p, "^[-A-Za-z0-9_]*$",
+                                   (AP_REG_EXTENDED | AP_REG_NOSUB ));
     ap_assert(preg != NULL);
 
     if (ap_regexec(preg, name, 0, NULL, 0)) {
@@ -318,7 +318,7 @@
         }
         else {
             new->preg = ap_pregcomp(cmd->pool, regex,
-                                    (REG_EXTENDED | (icase ? REG_ICASE : 0)));
+                                    (AP_REG_EXTENDED | (icase ? AP_REG_ICASE : 0)));
             if (new->preg == NULL) {
                 return apr_pstrcat(cmd->pool, cmd->cmd->name,
                                    " regex could not be compiled.", NULL);
@@ -354,8 +354,8 @@
              */
             if (is_header_regex(cmd->pool, fname)) {
                 new->pnamereg = ap_pregcomp(cmd->pool, fname,
-                                            (REG_EXTENDED | REG_NOSUB
-                                             | (icase ? REG_ICASE : 0)));
+                                            (AP_REG_EXTENDED | AP_REG_NOSUB
+                                             | (icase ? AP_REG_ICASE : 0)));
                 if (new->pnamereg == NULL)
                     return apr_pstrcat(cmd->pool, cmd->cmd->name,
                                        "Header name regex could not be "
@@ -453,7 +453,7 @@
     apr_size_t val_len = 0;
     int i, j;
     char *last_name;
-    regmatch_t regm[AP_MAX_REG_MATCH];
+    ap_regmatch_t regm[AP_MAX_REG_MATCH];
 
     if (!ap_get_module_config(r->request_config, &setenvif_module)) {
         ap_set_module_config(r->request_config, &setenvif_module,
