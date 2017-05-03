--- ../modsecurity-2.9.1/nginx/modsecurity/ngx_http_modsecurity.c.orig	2017-04-15 10:45:12.886736000 -0400
+++ ../modsecurity-2.9.1/nginx/modsecurity/ngx_http_modsecurity.c	2017-04-15 10:45:59.921529000 -0400
@@ -528,9 +528,15 @@
 
         hc = r->http_connection;
 
+#if defined(nginx_version) && nginx_version >= 1011011
+        if (hc->free && size == cscf->large_client_header_buffers.size) {
+
+            buf = hc->free->buf;
+#else
         if (hc->nfree && size == cscf->large_client_header_buffers.size) {
 
             buf = hc->free[--hc->nfree];
+#endif
 
             ngx_log_debug2(NGX_LOG_DEBUG_HTTP, r->connection->log, 0,
                            "ModSecurity: use http free large header buffer: %p %uz",
