--- ./modules/metadata/mod_usertrack.c.orig	2006-07-12 07:40:55.000000000 +0000
+++ ./modules/metadata/mod_usertrack.c	2010-10-21 05:40:53.653628850 +0000
@@ -84,7 +84,7 @@
     char *cookie_name;
     char *cookie_domain;
     char *regexp_string;  /* used to compile regexp; save for debugging */
-    regex_t *regexp;  /* used to find usertrack cookie in cookie header */
+    ap_regex_t *regexp;  /* used to find usertrack cookie in cookie header */
 } cookie_dir_rec;
 
 /* Make Cookie: Now we have to generate something that is going to be
@@ -201,7 +201,7 @@
                                       cookie_name,
                                       "=([^;]+)", NULL);
 
-    dcfg->regexp = ap_pregcomp(p, dcfg->regexp_string, REG_EXTENDED);
+    dcfg->regexp = ap_pregcomp(p, dcfg->regexp_string, AP_REG_EXTENDED);
     ap_assert(dcfg->regexp != NULL);
 }
 
@@ -210,7 +210,7 @@
     cookie_dir_rec *dcfg = ap_get_module_config(r->per_dir_config,
 						&usertrack_module);
     const char *cookie_header;
-    regmatch_t regm[NUM_SUBS];
+    ap_regmatch_t regm[NUM_SUBS];
 
     /* Do not run in subrequests */
     if (!dcfg->enabled || r->main) {
