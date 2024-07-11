--- ../ngx_http_redis-0.3.9/ngx_http_redis_module.c.orig	2022-07-10 22:10:19.031893000 -0400
+++ ../ngx_http_redis-0.3.9/ngx_http_redis_module.c	2022-07-10 22:09:41.271731000 -0400
@@ -562,7 +562,7 @@
         /* if defined gzip_flag... */
         if (rlcf->gzip_flag) {
             /* hash init */
-            h = ngx_list_push(&r->upstream->headers_in.headers);
+            h = ngx_list_push(&r->headers_out.headers);
             if (h == NULL) {
                 return NGX_ERROR;
             }
@@ -571,19 +571,11 @@
              * add Content-Encoding header for future gunzipping
              * with ngx_http_gunzip_filter module
              */
-            h->hash = ngx_hash(ngx_hash(ngx_hash(ngx_hash(
-                                ngx_hash(ngx_hash(ngx_hash(
-                                ngx_hash(ngx_hash(ngx_hash(
-                                ngx_hash(ngx_hash(ngx_hash(
-                                ngx_hash(ngx_hash('c', 'o'), 'n'), 't'), 'e'),
-                                 'n'), 't'), '-'), 'e'), 'n'), 'c'), 'o'),
-                                 'd'), 'i'), 'n'), 'g');
+            h->hash = 1;
+            h->next = NULL;
             ngx_str_set(&h->key, "Content-Encoding");
             ngx_str_set(&h->value, "gzip");
-            h->lowcase_key = (u_char*) "content-encoding";
-#if (NGX_HTTP_GZIP)
-            u->headers_in.content_encoding = h;
-#endif
+            r->headers_out.content_encoding = h;
         }
 
         /* try to find end of string */
