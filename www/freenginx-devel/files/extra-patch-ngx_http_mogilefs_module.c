--- ../nginx_mogilefs_module-1.0.4/ngx_http_mogilefs_module.c.orig	2015-04-21 21:16:22.251692000 +0300
+++ ../nginx_mogilefs_module-1.0.4/ngx_http_mogilefs_module.c	2015-04-21 21:16:39.460724000 +0300
@@ -316,9 +316,6 @@
 
     u->peer.log = r->connection->log;
     u->peer.log_error = NGX_ERROR_ERR;
-#if (NGX_THREADS)
-    u->peer.lock = &r->connection->lock;
-#endif
 
     u->output.tag = (ngx_buf_tag_t) &ngx_http_mogilefs_module;
 
