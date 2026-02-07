--- ../nginx-ct-93e9884/ngx_stream_ssl_ct_module.c.orig	2024-04-18 12:32:44.086600000 -0400
+++ ../nginx-ct-93e9884/ngx_stream_ssl_ct_module.c	2024-04-18 12:37:40.764525000 -0400
@@ -70,7 +70,11 @@
 
 static char *ngx_stream_ssl_ct_merge_srv_conf(ngx_conf_t *cf, void *parent,
     void *child) {
+#if nginx_version >= 1025005
+    ngx_stream_ssl_srv_conf_t *ssl_conf = ngx_stream_conf_get_module_srv_conf(cf,
+#else
     ngx_stream_ssl_conf_t *ssl_conf = ngx_stream_conf_get_module_srv_conf(cf,
+#endif
         ngx_stream_ssl_module);
 
     ngx_array_t *certificates;
