--- ./modules/mappers/mod_alias.c.orig	2006-07-12 07:40:55.000000000 +0000
+++ ./modules/mappers/mod_alias.c	2010-10-21 05:40:53.667623114 +0000
@@ -40,7 +40,7 @@
     const char *real;
     const char *fake;
     char *handler;
-    regex_t *regexp;
+    ap_regex_t *regexp;
     int redir_status;                /* 301, 302, 303, 410, etc */
 } alias_entry;
 
@@ -112,7 +112,7 @@
     /* XX r can NOT be relative to DocumentRoot here... compat bug. */
 
     if (use_regex) {
-        new->regexp = ap_pregcomp(cmd->pool, f, REG_EXTENDED);
+        new->regexp = ap_pregcomp(cmd->pool, f, AP_REG_EXTENDED);
         if (new->regexp == NULL)
             return "Regular expression could not be compiled.";
         new->real = r;
@@ -176,7 +176,7 @@
     alias_server_conf *serverconf = ap_get_module_config(s->module_config,
                                                          &alias_module);
     int status = (int) (long) cmd->info;
-    regex_t *r = NULL;
+    ap_regex_t *r = NULL;
     const char *f = arg2;
     const char *url = arg3;
 
@@ -196,7 +196,7 @@
     }
 
     if (use_regex) {
-        r = ap_pregcomp(cmd->pool, f, REG_EXTENDED);
+        r = ap_pregcomp(cmd->pool, f, AP_REG_EXTENDED);
         if (r == NULL)
             return "Regular expression could not be compiled.";
     }
@@ -314,7 +314,7 @@
                             int doesc, int *status)
 {
     alias_entry *entries = (alias_entry *) aliases->elts;
-    regmatch_t regm[AP_MAX_REG_MATCH];
+    ap_regmatch_t regm[AP_MAX_REG_MATCH];
     char *found = NULL;
     int i;
 
