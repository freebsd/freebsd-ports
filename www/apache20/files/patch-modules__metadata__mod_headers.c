--- ./modules/metadata/mod_headers.c.orig	2006-07-12 07:40:55.000000000 +0000
+++ ./modules/metadata/mod_headers.c	2010-10-21 05:40:53.655623801 +0000
@@ -113,7 +113,7 @@
     hdr_actions action;
     char *header;
     apr_array_header_t *ta;   /* Array of format_tag structs */
-    regex_t *regex;
+    ap_regex_t *regex;
     const char *condition_var;
 } header_entry;
 
@@ -344,13 +344,13 @@
             return "header unset takes two arguments";
     }
     else if (new->action == hdr_echo) {
-        regex_t *regex;
+        ap_regex_t *regex;
         if (value)
             return "Header echo takes two arguments";
         else if (cmd->info == &hdr_in)
             return "Header echo only valid on Header directive";
         else {
-            regex = ap_pregcomp(cmd->pool, hdr, REG_EXTENDED | REG_NOSUB);
+            regex = ap_pregcomp(cmd->pool, hdr, AP_REG_EXTENDED | AP_REG_NOSUB);
             if (regex == NULL) {
                 return "Header echo regex could not be compiled";
             }
