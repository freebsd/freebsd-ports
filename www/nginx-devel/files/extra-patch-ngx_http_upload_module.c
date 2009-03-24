--- ../nginx_upload_module-2.0.8/ngx_http_upload_module.c.orig	2009-03-24 10:43:49.000000000 +0300
+++ ../nginx_upload_module-2.0.8/ngx_http_upload_module.c	2009-03-24 11:06:15.000000000 +0300
@@ -208,6 +208,10 @@
     void *conf);
 static void ngx_upload_cleanup_handler(void *data);
 
+static ngx_path_init_t	ngx_http_upload_temp_path = {
+    ngx_string(NGX_HTTP_PROXY_TEMP_PATH), { 1, 2, 0 }
+};
+
 /*
  * upload_init_ctx
  *
@@ -1145,10 +1149,10 @@
 
     ngx_conf_merge_str_value(conf->url, prev->url, "");
 
-    ngx_conf_merge_path_value(conf->store_path,
+    ngx_conf_merge_path_value(cf,
+			      &conf->store_path,
                               prev->store_path,
-                              NGX_HTTP_PROXY_TEMP_PATH, 1, 2, 0,
-                              ngx_garbage_collector_temp_handler, cf);
+                              &ngx_http_upload_temp_path);
 
     ngx_conf_merge_uint_value(conf->store_access,
                               prev->store_access, 0600);
