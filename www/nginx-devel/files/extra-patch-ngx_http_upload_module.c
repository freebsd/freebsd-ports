--- ../nginx_upload_module-2.0.10/ngx_http_upload_module.c.orig	2009-11-19 12:10:09.000000000 +0300
+++ ../nginx_upload_module-2.0.10/ngx_http_upload_module.c	2009-11-19 12:52:53.000000000 +0300
@@ -1558,9 +1595,14 @@
 
     ngx_str_t                  *value;
 #if (NGX_PCRE)
+#if defined nginx_version && nginx_version >= 8025
+    ngx_regex_compile_t         rc;
+    u_char                      errstr[NGX_MAX_CONF_ERRSTR];
+#else
     ngx_int_t                   n;
     ngx_str_t                  err;
 #endif
+#endif
     ngx_http_upload_field_filter_t *f;
 
     value = cf->args->elts;
@@ -1579,6 +1621,22 @@
     }
 
 #if (NGX_PCRE)
+#if defined nginx_version && nginx_version >= 8025
+    ngx_memzero(&rc, sizeof(ngx_regex_compile_t));
+
+    rc.pattern = value[1];
+    rc.pool = cf->pool;
+    rc.err.len = NGX_MAX_CONF_ERRSTR;
+    rc.err.data = errstr;
+
+    if(ngx_regex_compile(&rc) != NGX_OK) {
+        ngx_conf_log_error(NGX_LOG_EMERG, cf, 0, "%V", &rc.err);
+        return NGX_CONF_ERROR;
+    }
+
+    f->regex = rc.regex;
+    f->ncaptures = rc.captures;
+#else
     f->regex = ngx_regex_compile(&value[1], 0, cf->pool, &err);
 
     if (f->regex == NULL) {
@@ -1596,6 +1654,7 @@
     }
 
     f->ncaptures = n;
+#endif
 #else
     f->text.len = value[1].len;
     f->text.data = value[1].data;
