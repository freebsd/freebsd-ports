--- ./modules/metadata/mod_version.c.orig	2006-07-12 07:40:55.000000000 +0000
+++ ./modules/metadata/mod_version.c	2010-10-21 05:40:53.654632332 +0000
@@ -142,11 +142,11 @@
 static int match_version(apr_pool_t *pool, char *version_string,
                          const char **error)
 {
-    regex_t *compiled;
+    ap_regex_t *compiled;
     const char *to_match;
     int rc;
 
-    compiled = ap_pregcomp(pool, version_string, REG_EXTENDED);
+    compiled = ap_pregcomp(pool, version_string, AP_REG_EXTENDED);
     if (!compiled) {
         *error = "Unable to compile regular expression";
         return 0;
