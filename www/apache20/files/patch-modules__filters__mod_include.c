--- ./modules/filters/mod_include.c.orig	2006-07-12 07:40:55.000000000 +0000
+++ ./modules/filters/mod_include.c	2010-10-21 05:40:53.670622104 +0000
@@ -1173,11 +1173,11 @@
 static int re_check(request_rec *r, include_ctx_t *ctx, 
                     char *string, char *rexp)
 {
-    regex_t *compiled;
-    const apr_size_t nres = sizeof(*ctx->re_result) / sizeof(regmatch_t);
+    ap_regex_t *compiled;
+    const apr_size_t nres = sizeof(*ctx->re_result) / sizeof(ap_regmatch_t);
     int regex_error;
 
-    compiled = ap_pregcomp(r->pool, rexp, REG_EXTENDED | REG_NOSUB);
+    compiled = ap_pregcomp(r->pool, rexp, AP_REG_EXTENDED | AP_REG_NOSUB);
     if (compiled == NULL) {
         ap_log_rerror(APLOG_MARK, APLOG_ERR, 0, r,
                       "unable to compile pattern \"%s\"", rexp);
