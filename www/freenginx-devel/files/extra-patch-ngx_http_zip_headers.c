--- ../mod_zip-a9f9afa/ngx_http_zip_headers.c.orig	2025-09-04 15:55:16.000000000 -0400
+++ ../mod_zip-a9f9afa/ngx_http_zip_headers.c	2026-06-14 16:27:32.254320000 -0400
@@ -21,7 +21,7 @@
 ngx_int_t 
 ngx_http_zip_add_cache_control(ngx_http_request_t *r)
 {
-#ifdef NGX_ZIP_MULTI_HEADERS_LINKED_LISTS
+#if defined(NGX_ZIP_MULTI_HEADERS_LINKED_LISTS) || defined(freenginx)
     ngx_table_elt_t            *cc;
 
     /* convoluted way of adding Cache-Control: max-age=0 */
@@ -323,7 +323,7 @@
                                  ngx_http_variable_value_t *v, ngx_str_t *var,
                                  ngx_list_part_t *part, size_t prefix)
 {
-#ifdef NGX_ZIP_MULTI_HEADERS_LINKED_LISTS
+#if defined(NGX_ZIP_MULTI_HEADERS_LINKED_LISTS) || defined(freenginx)
     return ngx_http_variable_unknown_header(r, v, var, part, prefix);
 #else
     return ngx_http_variable_unknown_header(v, var, part, prefix);
