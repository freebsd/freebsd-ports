--- libclamav/regex_pcre.c.orig	2018-01-23 21:04:06 UTC
+++ libclamav/regex_pcre.c
@@ -112,7 +112,8 @@ int cli_pcre_addoptions(struct cli_pcre_
 #if USING_PCRE2
 int cli_pcre_compile(struct cli_pcre_data *pd, long long unsigned match_limit, long long unsigned match_limit_recursion, unsigned int options, int opt_override)
 {
-    int errornum, erroffset;
+    int errornum;
+    size_t erroffset;
     pcre2_general_context *gctx;
     pcre2_compile_context *cctx;
 
