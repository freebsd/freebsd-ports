--- bundle/nginx-1.31.9/src/core/ngx_output_chain.c.orig	2026-11-25 07:53:13 UTC
+++ bundle/nginx-1.31.9/src/core/ngx_output_chain.c
@@ -670,7 +670,7 @@ ngx_chain_writer(void *data, ngx_chain_t *in)
 {
     ngx_chain_writer_ctx_t *ctx = data;
 
-    off_t              size;
+    off_t              size, sent;
     ngx_chain_t       *cl, *ln, *chain;
     ngx_connection_t  *c;
 
@@ -787,6 +787,8 @@ ngx_chain_writer(void *data, ngx_chain_t *in)
         return NGX_OK;
     }
 
+    sent = c->sent;
+
     chain = c->send_chain(c, ctx->out, ctx->limit);
 
     ngx_log_debug1(NGX_LOG_DEBUG_CORE, c->log, 0,
@@ -796,7 +798,7 @@ ngx_chain_writer(void *data, ngx_chain_t *in)
         return NGX_ERROR;
     }
 
-    if (chain && c->write->ready) {
+    if (chain && c->write->ready && c->sent != sent) {
         ngx_post_event(c->write, &ngx_posted_next_events);
     }
 
