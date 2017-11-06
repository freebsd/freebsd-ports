--- ../lua-nginx-module-0.10.8/src/ngx_http_lua_headers.c.orig	2017-04-15 10:57:48.875770000 -0400
+++ ../lua-nginx-module-0.10.8/src/ngx_http_lua_headers.c	2017-04-15 11:02:00.492564000 -0400
@@ -26,6 +26,9 @@
 static int ngx_http_lua_ngx_req_header_clear(lua_State *L);
 static int ngx_http_lua_ngx_req_header_set(lua_State *L);
 static int ngx_http_lua_ngx_resp_get_headers(lua_State *L);
+#if nginx_version >= 1011011
+void ngx_http_lua_ngx_raw_header_cleanup(void *data);
+#endif
 
 
 static int
@@ -77,6 +80,11 @@
     size_t                       size;
     ngx_buf_t                   *b, *first = NULL;
     ngx_int_t                    i, j;
+#if nginx_version >= 1011011
+    ngx_buf_t                  **bb;
+    ngx_chain_t                 *cl;
+    ngx_http_lua_main_conf_t    *lmcf;
+#endif
     ngx_connection_t            *c;
     ngx_http_request_t          *r, *mr;
     ngx_http_connection_t       *hc;
@@ -93,6 +101,10 @@
         return luaL_error(L, "no request object found");
     }
 
+#if nginx_version >= 1011011
+    lmcf = ngx_http_get_module_main_conf(r, ngx_http_lua_module);
+#endif
+
     ngx_http_lua_check_fake_request(L, r);
 
     mr = r->main;
@@ -109,8 +121,13 @@
     dd("hc->nbusy: %d", (int) hc->nbusy);
 
     if (hc->nbusy) {
+#if nginx_version >= 1011011
+        dd("hc->busy: %p %p %p %p", hc->busy->buf->start, hc->busy->buf->pos,
+           hc->busy->buf->last, hc->busy->buf->end);
+#else
         dd("hc->busy: %p %p %p %p", hc->busy[0]->start, hc->busy[0]->pos,
            hc->busy[0]->last, hc->busy[0]->end);
+#endif
     }
 
     dd("request line: %p %p", mr->request_line.data,
@@ -146,9 +163,37 @@
     dd("size: %d", (int) size);
 
     if (hc->nbusy) {
+#if nginx_version >= 1011011
+        if (hc->nbusy > lmcf->busy_buf_ptr_count) {
+            if (lmcf->busy_buf_ptrs) {
+                ngx_free(lmcf->busy_buf_ptrs);
+            }
+
+            lmcf->busy_buf_ptrs = ngx_alloc(hc->nbusy * sizeof(ngx_buf_t *),
+                                            r->connection->log);
+
+            if (lmcf->busy_buf_ptrs == NULL) {
+                return luaL_error(L, "no memory");
+            }
+
+            lmcf->busy_buf_ptr_count = hc->nbusy;
+        }
+
+        bb = lmcf->busy_buf_ptrs;
+        for (cl = hc->busy; cl; cl = cl->next) {
+            *bb++ = cl->buf;
+        }
+#endif
         b = NULL;
+
+#if nginx_version >= 1011011
+        bb = lmcf->busy_buf_ptrs;
+        for (i = hc->nbusy; i > 0; i--) {
+            b = bb[i - 1];
+#else
         for (i = 0; i < hc->nbusy; i++) {
             b = hc->busy[i];
+#endif
 
             dd("busy buf: %d: [%.*s]", (int) i, (int) (b->pos - b->start),
                b->start);
@@ -223,8 +268,15 @@
     }
 
     if (hc->nbusy) {
+
+#if nginx_version >= 1011011
+        bb = lmcf->busy_buf_ptrs;
+        for (i = hc->nbusy - 1; i >= 0; i--) {
+            b = bb[i];
+#else
         for (i = 0; i < hc->nbusy; i++) {
             b = hc->busy[i];
+#endif
 
             if (!found) {
                 if (b != first) {
@@ -1431,4 +1483,20 @@
 #endif /* NGX_LUA_NO_FFI_API */
 
 
+#if nginx_version >= 1011011
+void
+ngx_http_lua_ngx_raw_header_cleanup(void *data)
+{
+    ngx_http_lua_main_conf_t  *lmcf;
+
+    lmcf = (ngx_http_lua_main_conf_t *) data;
+
+    if (lmcf->busy_buf_ptrs) {
+        ngx_free(lmcf->busy_buf_ptrs);
+        lmcf->busy_buf_ptrs = NULL;
+    }
+}
+#endif
+
+
 /* vi:set ft=c ts=4 sw=4 et fdm=marker: */
