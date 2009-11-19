--- ../ngx_http_redis-0.2.0/ngx_http_redis_module.c.orig	2009-11-19 11:21:17.000000000 +0300
+++ ../ngx_http_redis-0.2.0/ngx_http_redis_module.c	2009-11-19 11:21:57.000000000 +0300
@@ -244,7 +244,7 @@
     vv[0] = ngx_http_get_indexed_variable(r, rlcf->db);
 
     if (vv[0] == NULL || vv[0]->not_found || vv[0]->len == 0) {
-        ngx_log_debug1(NGX_LOG_DEBUG_HTTP, r->connection->log, 0,
+        ngx_log_debug0(NGX_LOG_DEBUG_HTTP, r->connection->log, 0,
                        "select 0 redis database" );
         len = sizeof("select 0") - 1;
     } else {
@@ -287,7 +287,7 @@
     ctx->key.data = b->last;
 
     if (vv[0] == NULL || vv[0]->not_found || vv[0]->len == 0) {
-        ngx_log_debug1(NGX_LOG_DEBUG_HTTP, r->connection->log, 0,
+        ngx_log_debug0(NGX_LOG_DEBUG_HTTP, r->connection->log, 0,
                        "select 0 redis database" );
         *b->last++ = '0';
     } else {
