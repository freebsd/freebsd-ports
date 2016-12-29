--- lib/core/request.c.orig	2016-09-13 06:57:03 UTC
+++ lib/core/request.c
@@ -31,21 +31,24 @@
 
 #define INITIAL_INBUFSZ 8192
 
-struct st_delegate_request_deferred_t {
+struct st_deferred_request_action_t {
+    h2o_timeout_entry_t timeout;
     h2o_req_t *req;
+};
+
+struct st_delegate_request_deferred_t {
+    struct st_deferred_request_action_t super;
     h2o_handler_t *current_handler;
-    h2o_timeout_entry_t _timeout;
 };
 
 struct st_reprocess_request_deferred_t {
-    h2o_req_t *req;
+    struct st_deferred_request_action_t super;
     h2o_iovec_t method;
     const h2o_url_scheme_t *scheme;
     h2o_iovec_t authority;
     h2o_iovec_t path;
     h2o_req_overrides_t *overrides;
     int is_delegated;
-    h2o_timeout_entry_t _timeout;
 };
 
 struct st_send_error_deferred_t {
@@ -57,6 +60,21 @@ struct st_send_error_deferred_t {
     h2o_timeout_entry_t _timeout;
 };
 
+static void on_deferred_action_dispose(void *_action)
+{
+    struct st_deferred_request_action_t *action = _action;
+    if (h2o_timeout_is_linked(&action->timeout))
+        h2o_timeout_unlink(&action->timeout);
+}
+
+static struct st_deferred_request_action_t *create_deferred_action(h2o_req_t *req, size_t sz, h2o_timeout_cb cb)
+{
+    struct st_deferred_request_action_t *action = h2o_mem_alloc_shared(&req->pool, sz, on_deferred_action_dispose);
+    *action = (struct st_deferred_request_action_t){{0, cb}, req};
+    h2o_timeout_link(req->conn->ctx->loop, &req->conn->ctx->zero_timeout, &action->timeout);
+    return action;
+}
+
 static h2o_hostconf_t *find_hostconf(h2o_hostconf_t **hostconfs, h2o_iovec_t authority, uint16_t default_port)
 {
     h2o_iovec_t hostname;
@@ -205,6 +223,7 @@ void h2o_init_request(h2o_req_t *req, h2
     req->preferred_chunk_size = SIZE_MAX;
 
     if (src != NULL) {
+        size_t i;
 #define COPY(buf)                                                                                                                  \
     do {                                                                                                                           \
         req->buf.base = h2o_mem_alloc_pool(&req->pool, src->buf.len);                                                              \
@@ -216,9 +235,6 @@ void h2o_init_request(h2o_req_t *req, h2
         COPY(input.path);
         req->input.scheme = src->input.scheme;
         req->version = src->version;
-        h2o_vector_reserve(&req->pool, &req->headers, src->headers.size);
-        memcpy(req->headers.entries, src->headers.entries, sizeof(req->headers.entries[0]) * src->headers.size);
-        req->headers.size = src->headers.size;
         req->entity = src->entity;
         req->http1_is_persistent = src->http1_is_persistent;
         req->timestamps = src->timestamps;
@@ -229,8 +245,19 @@ void h2o_init_request(h2o_req_t *req, h2
             req->upgrade.len = 0;
         }
 #undef COPY
+        h2o_vector_reserve(&req->pool, &req->headers, src->headers.size);
+        req->headers.size = src->headers.size;
+        for (i = 0; i != src->headers.size; ++i) {
+            h2o_header_t *dst_header = req->headers.entries + i, *src_header = src->headers.entries + i;
+            if (h2o_iovec_is_token(src_header->name)) {
+                dst_header->name = src_header->name;
+            } else {
+                dst_header->name = h2o_mem_alloc_pool(&req->pool, sizeof(*dst_header->name));
+                *dst_header->name = h2o_strdup(&req->pool, src_header->name->base, src_header->name->len);
+            }
+            dst_header->value = h2o_strdup(&req->pool, src_header->value.base, src_header->value.len);
+        }
         if (src->env.size != 0) {
-            size_t i;
             h2o_vector_reserve(&req->pool, &req->env, src->env.size);
             req->env.size = src->env.size;
             for (i = 0; i != req->env.size; ++i)
@@ -276,16 +303,16 @@ void h2o_delegate_request(h2o_req_t *req
 
 static void on_delegate_request_cb(h2o_timeout_entry_t *entry)
 {
-    struct st_delegate_request_deferred_t *args = H2O_STRUCT_FROM_MEMBER(struct st_delegate_request_deferred_t, _timeout, entry);
-    h2o_delegate_request(args->req, args->current_handler);
+    struct st_delegate_request_deferred_t *args =
+        H2O_STRUCT_FROM_MEMBER(struct st_delegate_request_deferred_t, super.timeout, entry);
+    h2o_delegate_request(args->super.req, args->current_handler);
 }
 
 void h2o_delegate_request_deferred(h2o_req_t *req, h2o_handler_t *current_handler)
 {
-    struct st_delegate_request_deferred_t *args = h2o_mem_alloc_pool(&req->pool, sizeof(*args));
-    *args = (struct st_delegate_request_deferred_t){req, current_handler};
-    args->_timeout.cb = on_delegate_request_cb;
-    h2o_timeout_link(req->conn->ctx->loop, &req->conn->ctx->zero_timeout, &args->_timeout);
+    struct st_delegate_request_deferred_t *args =
+        (struct st_delegate_request_deferred_t *)create_deferred_action(req, sizeof(*args), on_delegate_request_cb);
+    args->current_handler = current_handler;
 }
 
 void h2o_reprocess_request(h2o_req_t *req, h2o_iovec_t method, const h2o_url_scheme_t *scheme, h2o_iovec_t authority,
@@ -335,17 +362,23 @@ void h2o_reprocess_request(h2o_req_t *re
 
 static void on_reprocess_request_cb(h2o_timeout_entry_t *entry)
 {
-    struct st_reprocess_request_deferred_t *args = H2O_STRUCT_FROM_MEMBER(struct st_reprocess_request_deferred_t, _timeout, entry);
-    h2o_reprocess_request(args->req, args->method, args->scheme, args->authority, args->path, args->overrides, args->is_delegated);
+    struct st_reprocess_request_deferred_t *args =
+        H2O_STRUCT_FROM_MEMBER(struct st_reprocess_request_deferred_t, super.timeout, entry);
+    h2o_reprocess_request(args->super.req, args->method, args->scheme, args->authority, args->path, args->overrides,
+                          args->is_delegated);
 }
 
 void h2o_reprocess_request_deferred(h2o_req_t *req, h2o_iovec_t method, const h2o_url_scheme_t *scheme, h2o_iovec_t authority,
                                     h2o_iovec_t path, h2o_req_overrides_t *overrides, int is_delegated)
 {
-    struct st_reprocess_request_deferred_t *args = h2o_mem_alloc_pool(&req->pool, sizeof(*args));
-    *args = (struct st_reprocess_request_deferred_t){req, method, scheme, authority, path, overrides, is_delegated};
-    args->_timeout.cb = on_reprocess_request_cb;
-    h2o_timeout_link(req->conn->ctx->loop, &req->conn->ctx->zero_timeout, &args->_timeout);
+    struct st_reprocess_request_deferred_t *args =
+        (struct st_reprocess_request_deferred_t *)create_deferred_action(req, sizeof(*args), on_reprocess_request_cb);
+    args->method = method;
+    args->scheme = scheme;
+    args->authority = authority;
+    args->path = path;
+    args->overrides = overrides;
+    args->is_delegated = is_delegated;
 }
 
 void h2o_start_response(h2o_req_t *req, h2o_generator_t *generator)
