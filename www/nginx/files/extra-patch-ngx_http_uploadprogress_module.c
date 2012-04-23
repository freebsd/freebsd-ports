--- ../masterzen-nginx-upload-progress-module-c7c663f/ngx_http_uploadprogress_module.c.orig	2012-02-15 19:50:03.000000000 +0400
+++ ../masterzen-nginx-upload-progress-module-c7c663f/ngx_http_uploadprogress_module.c	2012-02-15 19:53:58.000000000 +0400
@@ -1446,18 +1446,12 @@
 
 
     lzcf->timeout = ngx_parse_time(&value[2], 1);
-    if (lzcf->timeout == NGX_ERROR) {
+    if (lzcf->timeout == (time_t) NGX_ERROR) {
         ngx_conf_log_error(NGX_LOG_EMERG, cf, 0,
                            "track_uploads \"%V\" timeout value invalid", &value[1]);
         return NGX_CONF_ERROR;
     }
 
-    if (lzcf->timeout == NGX_PARSE_LARGE_TIME) {
-        ngx_conf_log_error(NGX_LOG_EMERG, cf, 0,
-                           "track_uploads \"%V\" timeout value must be less than 68 years", &value[1]);
-        return NGX_CONF_ERROR;
-    }
-
     clcf = ngx_http_conf_get_module_loc_conf(cf, ngx_http_core_module);
     lzcf->handler = clcf->handler;
     if ( lzcf->handler == NULL )
