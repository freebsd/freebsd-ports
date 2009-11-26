--- ../nginx_upload_module-2.0.11/ngx_http_upload_module.c
+++ ../nginx_upload_module-2.0.11/ngx_http_upload_module.c
@@ -719,6 +719,10 @@ static ngx_int_t ngx_http_upload_body_handler(ngx_http_request_t *r) { /* {{{ */
         ngx_sprintf(r->headers_in.content_length->value.data, "%O", r->headers_in.content_length_n)
             - r->headers_in.content_length->value.data;
 
+#if defined nginx_version && nginx_version >= 8011
+    r->main->count--;
+#endif
+
     if(uri->len != 0 && uri->data[0] == '/') {
         rc = ngx_http_internal_redirect(r, uri, &args);
     }
