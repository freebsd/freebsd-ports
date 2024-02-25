--- src/http/modules/ngx_http_slice_filter_module.c.orig	2019-04-23 13:12:58 UTC
+++ src/http/modules/ngx_http_slice_filter_module.c
@@ -2,6 +2,10 @@
 /*
  * Copyright (C) Roman Arutyunyan
  * Copyright (C) Nginx, Inc.
+ * Copyright (C) Carey Gister
+ * Copyright (C) Metapeer, Inc.
+ *
+ * Retrieve slices with an optional look-a-head of N slices where N is a float value.
  */
 
 
@@ -9,13 +13,25 @@
 #include <ngx_core.h>
 #include <ngx_http.h>
 
+/*
+ * Location Configuration -- size is size of a slice, read_a_heads is number of
+ * blocks to look a head: 0, will not limit the number of blocks. Blocks will be
+ * retrieved as quickly as GETs can be issued and returned.
+ */
 
 typedef struct {
     size_t               size;
+    float                read_a_heads;
 } ngx_http_slice_loc_conf_t;
 
 
 typedef struct {
+    size_t               requested_bytes;
+    size_t               received_bytes;
+    size_t               skipped_first_slice;
+} ngx_http_slice_read_a_head_t;
+
+typedef struct {
     off_t                start;
     off_t                end;
     ngx_str_t            range;
@@ -23,6 +39,7 @@ typedef struct {
     unsigned             last:1;
     unsigned             active:1;
     ngx_http_request_t  *sr;
+    ngx_http_slice_read_a_head_t  *read_a_head;
 } ngx_http_slice_ctx_t;
 
 
@@ -46,6 +63,8 @@ static char *ngx_http_slice_merge_loc_conf(ngx_conf_t 
     void *child);
 static ngx_int_t ngx_http_slice_add_variables(ngx_conf_t *cf);
 static ngx_int_t ngx_http_slice_init(ngx_conf_t *cf);
+static char * ngx_conf_set_float_slot(ngx_conf_t *cf, ngx_command_t *cmd,
+    void *conf);
 
 
 static ngx_command_t  ngx_http_slice_filter_commands[] = {
@@ -57,6 +76,13 @@ static ngx_command_t  ngx_http_slice_filter_commands[]
       offsetof(ngx_http_slice_loc_conf_t, size),
       NULL },
 
+    { ngx_string("slice_read_ahead"),
+      NGX_HTTP_MAIN_CONF|NGX_HTTP_SRV_CONF|NGX_HTTP_LOC_CONF|NGX_CONF_TAKE1,
+      ngx_conf_set_float_slot,
+      NGX_HTTP_LOC_CONF_OFFSET,
+      offsetof(ngx_http_slice_loc_conf_t, read_a_heads),
+      NULL },
+
       ngx_null_command
 };
 
@@ -102,11 +128,11 @@ static ngx_int_t
 ngx_http_slice_header_filter(ngx_http_request_t *r)
 {
     off_t                            end;
-    ngx_int_t                        rc;
+    ngx_int_t                        rc, rc1;
     ngx_table_elt_t                 *h;
     ngx_http_slice_ctx_t            *ctx;
     ngx_http_slice_loc_conf_t       *slcf;
-    ngx_http_slice_content_range_t   cr;
+    ngx_http_slice_content_range_t   cr, cr1;
 
     ctx = ngx_http_get_module_ctx(r, ngx_http_slice_filter_module);
     if (ctx == NULL) {
@@ -187,6 +213,23 @@ ngx_http_slice_header_filter(ngx_http_request_t *r)
     rc = ngx_http_next_header_filter(r);
 
     if (r != r->main) {
+        if (ctx->read_a_head != NULL) {
+            ngx_log_debug5(NGX_LOG_DEBUG_HTTP, r->connection->log, 0,
+                "http slice header (subrequest) requested_bytes: %uz, size: %uz, range: %O/%O, end: %O",
+                ctx->read_a_head->requested_bytes, slcf->size, cr.start,
+                cr.end, end);
+
+            if (end != cr.start) {
+                ctx->read_a_head->requested_bytes +=
+                    ngx_min(slcf->size,
+                        (size_t) end - (size_t) cr.start);
+            }
+
+            ngx_log_debug2(NGX_LOG_DEBUG_HTTP, r->connection->log, 0,
+                "http slice header (subrequest) new requested_bytes: %uz, size: %uz",
+                 ctx->read_a_head->requested_bytes, slcf->size);
+        }
+
         return rc;
     }
 
@@ -201,8 +244,68 @@ ngx_http_slice_header_filter(ngx_http_request_t *r)
         ctx->end = r->headers_out.content_offset
                    + r->headers_out.content_length_n;
 
+        /* Update requested bytes for the new chunk. */
+        if (ctx->read_a_head != NULL) {
+            ngx_log_debug4(NGX_LOG_DEBUG_HTTP, r->connection->log, 0,
+                "http slice header (main request, partial) requested_bytes: %uz, size: %uz, start/end (%O/%O)",
+                ctx->read_a_head->requested_bytes, slcf->size,
+                ctx->start, ctx->end);
+
+            if (ctx->end != ctx->start) {
+                ctx->read_a_head->requested_bytes +=
+                    ngx_min(slcf->size,
+                        (size_t) ctx->end - (size_t) ctx->start);
+            }
+
+            ngx_log_debug4(NGX_LOG_DEBUG_HTTP, r->connection->log, 0,
+                "http slice header (main request, partial) new requested_bytes: %uz, size: %uz, start/end (%O/%O)",
+                ctx->read_a_head->requested_bytes, slcf->size, ctx->start, ctx->end);
+
+            /* Parse the new Content-Range, which may have been set by the Range
+               filter. If the start changed, then adjust the requested_byte count
+               by the difference between the slice start and the actual start.
+               These bytes will never be received. */
+
+            rc1 = ngx_http_slice_parse_content_range(r, &cr1);
+            ngx_log_debug(NGX_LOG_DEBUG_HTTP, r->connection->log, 0,
+                "http slice header (main request, partial): rc1: %d",
+                rc1);
+
+            if (rc1 == NGX_OK) {
+                ngx_log_debug2(NGX_LOG_DEBUG_HTTP, r->connection->log, 0,
+                    "http slice header (main request, partial new content range) cr1.start: %uz, cr1.end: %uz",
+                    cr1.start, cr1.end);
+
+                if (cr1.start != cr.start) {
+                    ctx->read_a_head->skipped_first_slice =
+                        cr1.start - (slcf->size * (cr1.start / slcf->size));
+
+                    ngx_log_debug3(NGX_LOG_DEBUG_HTTP, r->connection->log, 0,
+                        "http slice header (main request, partial) new cr.start: %uz, initial start: %uz, skipped first slice: %uz",
+                        cr1.start, cr.start,
+                        ctx->read_a_head->skipped_first_slice);
+                }
+            }
+        }
     } else {
         ctx->end = cr.complete_length;
+
+        /* Update the requested bytes for the new chunk. */
+        if (ctx->read_a_head != NULL) {
+            ngx_log_debug4(NGX_LOG_DEBUG_HTTP, r->connection->log, 0,
+                "http slice header (main request, full) requested_bytes: %uz, size: %uz, start/end (%O/%O)",
+                ctx->read_a_head->requested_bytes, slcf->size, ctx->start, ctx->end);
+
+            if (ctx->end != ctx->start) {
+                ctx->read_a_head->requested_bytes +=
+                    ngx_min(slcf->size,
+                        (size_t) ctx->end - (size_t) ctx->start);
+            }
+
+            ngx_log_debug4(NGX_LOG_DEBUG_HTTP, r->connection->log, 0,
+                "http slice header (main request, full) new requested_bytes: %uz, size: %uz, start/end (%O/%O)",
+                ctx->read_a_head->requested_bytes, slcf->size, ctx->start, ctx->end);
+        }
     }
 
     return rc;
@@ -216,14 +319,31 @@ ngx_http_slice_body_filter(ngx_http_request_t *r, ngx_
     ngx_chain_t                *cl;
     ngx_http_slice_ctx_t       *ctx;
     ngx_http_slice_loc_conf_t  *slcf;
+    size_t                      received, read_a_head_window, read_a_head_size;
 
     ctx = ngx_http_get_module_ctx(r, ngx_http_slice_filter_module);
 
-    if (ctx == NULL || r != r->main) {
+    if (ctx == NULL) {
         return ngx_http_next_body_filter(r, in);
     }
 
+    if (r != r->main) {
+        if (ctx->read_a_head != NULL) {
+            received = 0;
+            for (cl = in; cl; cl = cl->next) {
+                received = received + ngx_buf_size(cl->buf);
+            }
+
+            ctx->read_a_head->received_bytes += received;
+        }
+
+        return ngx_http_next_body_filter(r, in);
+    }
+
+    /* For the main request */
+    received = 0;
     for (cl = in; cl; cl = cl->next) {
+        received = received + ngx_buf_size(cl->buf);
         if (cl->buf->last_buf) {
             cl->buf->last_buf = 0;
             cl->buf->last_in_chain = 1;
@@ -232,6 +352,10 @@ ngx_http_slice_body_filter(ngx_http_request_t *r, ngx_
         }
     }
 
+    if (ctx->read_a_head != NULL) {
+        ctx->read_a_head->received_bytes += received;
+    }
+
     rc = ngx_http_next_body_filter(r, in);
 
     if (rc == NGX_ERROR || !ctx->last) {
@@ -258,6 +382,20 @@ ngx_http_slice_body_filter(ngx_http_request_t *r, ngx_
         return rc;
     }
 
+    slcf = ngx_http_get_module_loc_conf(r, ngx_http_slice_filter_module);
+
+    if (ctx->read_a_head != NULL) {
+        read_a_head_size = (size_t) (slcf->size * slcf->read_a_heads);
+        read_a_head_window = r->connection->sent + read_a_head_size;
+
+        if ((r->connection->sent != 0) &&
+            ((read_a_head_window + ctx->read_a_head->skipped_first_slice) < ctx->read_a_head->requested_bytes)) {
+            ngx_log_debug0(NGX_LOG_DEBUG_HTTP, r->connection->log, 0,
+                "http slice body filter defer subrequest: returning NGX_AGAIN");
+            return NGX_AGAIN;
+        }
+    }
+
     if (ngx_http_subrequest(r, &r->uri, &r->args, &ctx->sr, NULL,
                             NGX_HTTP_SUBREQUEST_CLONE)
         != NGX_OK)
@@ -267,8 +405,6 @@ ngx_http_slice_body_filter(ngx_http_request_t *r, ngx_
 
     ngx_http_set_ctx(ctx->sr, ctx, ngx_http_slice_filter_module);
 
-    slcf = ngx_http_get_module_loc_conf(r, ngx_http_slice_filter_module);
-
     ctx->range.len = ngx_sprintf(ctx->range.data, "bytes=%O-%O", ctx->start,
                                  ctx->start + (off_t) slcf->size - 1)
                      - ctx->range.data;
@@ -287,6 +423,7 @@ ngx_http_slice_parse_content_range(ngx_http_request_t 
     ngx_http_slice_content_range_t *cr)
 {
     off_t             start, end, complete_length, cutoff, cutlim;
+    ssize_t           len;
     u_char           *p;
     ngx_table_elt_t  *h;
 
@@ -300,6 +437,7 @@ ngx_http_slice_parse_content_range(ngx_http_request_t 
     }
 
     p = h->value.data + 6;
+    len = h->value.len - 6;
 
     cutoff = NGX_MAX_OFF_T_VALUE / 10;
     cutlim = NGX_MAX_OFF_T_VALUE % 10;
@@ -308,56 +446,62 @@ ngx_http_slice_parse_content_range(ngx_http_request_t 
     end = 0;
     complete_length = 0;
 
-    while (*p == ' ') { p++; }
+    while ((*p == ' ') && (len != 0)) { p++; len--; }
 
-    if (*p < '0' || *p > '9') {
+    if ((len == 0) || (*p < '0' || *p > '9')) {
         return NGX_ERROR;
     }
 
-    while (*p >= '0' && *p <= '9') {
+    while ((len != 0) && (*p >= '0' && *p <= '9')) {
         if (start >= cutoff && (start > cutoff || *p - '0' > cutlim)) {
             return NGX_ERROR;
         }
 
         start = start * 10 + (*p++ - '0');
+        len--;
     }
 
-    while (*p == ' ') { p++; }
+    while ((len != 0) && (*p == ' ')) { p++; len--; }
 
-    if (*p++ != '-') {
+    if ((len == 0) || (*p++ != '-')) {
         return NGX_ERROR;
     }
 
-    while (*p == ' ') { p++; }
+    len--;
 
-    if (*p < '0' || *p > '9') {
+    while ((len != 0) && (*p == ' ')) { p++; len--; }
+
+    if ((len == 0) || (*p < '0' || *p > '9')) {
         return NGX_ERROR;
     }
 
-    while (*p >= '0' && *p <= '9') {
+    while ((len != 0) && (*p >= '0' && *p <= '9')) {
         if (end >= cutoff && (end > cutoff || *p - '0' > cutlim)) {
             return NGX_ERROR;
         }
 
         end = end * 10 + (*p++ - '0');
+        len--;
     }
 
     end++;
 
-    while (*p == ' ') { p++; }
+    while ((len != 0) && (*p == ' ')) { p++; len--; }
 
-    if (*p++ != '/') {
+    if ((len == 0) || (*p++ != '/')) {
         return NGX_ERROR;
     }
 
-    while (*p == ' ') { p++; }
+    len--;
 
-    if (*p != '*') {
+    while ((len != 0) && (*p == ' ')) { p++; len--; }
+
+    if ((len != 0) && (*p != '*')) {
         if (*p < '0' || *p > '9') {
             return NGX_ERROR;
         }
 
-        while (*p >= '0' && *p <= '9') {
+        while ((len != 0) && (*p >= '0' && *p <= '9')) {
             if (complete_length >= cutoff
                 && (complete_length > cutoff || *p - '0' > cutlim))
             {
@@ -365,16 +509,18 @@ ngx_http_slice_parse_content_range(ngx_http_request_t 
             }
 
             complete_length = complete_length * 10 + (*p++ - '0');
+            len--;
         }
 
     } else {
         complete_length = -1;
         p++;
+        len--;
     }
 
-    while (*p == ' ') { p++; }
+    while ((len != 0) && (*p == ' ')) { p++; len--; }
 
-    if (*p != '\0') {
+    if (len != 0) {
         return NGX_ERROR;
     }
 
@@ -390,9 +536,10 @@ static ngx_int_t
 ngx_http_slice_range_variable(ngx_http_request_t *r,
     ngx_http_variable_value_t *v, uintptr_t data)
 {
-    u_char                     *p;
-    ngx_http_slice_ctx_t       *ctx;
-    ngx_http_slice_loc_conf_t  *slcf;
+    u_char                        *p;
+    ngx_http_slice_ctx_t          *ctx;
+    ngx_http_slice_loc_conf_t     *slcf;
+    ngx_http_slice_read_a_head_t  *read_a_head;
 
     ctx = ngx_http_get_module_ctx(r, ngx_http_slice_filter_module);
 
@@ -414,6 +561,15 @@ ngx_http_slice_range_variable(ngx_http_request_t *r,
             return NGX_ERROR;
         }
 
+        if (slcf->read_a_heads != 0.0) {
+            read_a_head = ngx_pcalloc(r->pool, sizeof(ngx_http_slice_read_a_head_t));
+            if (read_a_head == NULL) {
+                return NGX_ERROR;
+            }
+
+            ctx->read_a_head = read_a_head;
+        }
+
         ngx_http_set_ctx(r, ctx, ngx_http_slice_filter_module);
 
         p = ngx_pnalloc(r->pool, sizeof("bytes=-") - 1 + 2 * NGX_OFF_T_LEN);
@@ -488,6 +644,39 @@ ngx_http_slice_get_start(ngx_http_request_t *r)
 }
 
 
+static char *
+ngx_conf_set_float_slot(ngx_conf_t *cf, ngx_command_t *cmd, void *conf)
+{
+    char             *p = conf;
+    float            *np;
+    ngx_str_t        *value;
+    ngx_conf_post_t  *post;
+    ngx_int_t        val;
+
+    np = (float *) (p + cmd->offset);
+
+    if (*np != (float) NGX_CONF_UNSET) {
+        return "is duplicate";
+    }
+
+    value = cf->args->elts;
+    val = ngx_atofp(value[1].data, value[1].len, 3);
+
+    *np = (float) val / 1000.0;
+
+    if (*np == (float) NGX_ERROR) {
+        return "invalid number";
+    }
+
+    if (cmd->post) {
+        post = cmd->post;
+        return post->post_handler(cf, post, np);
+    }
+
+    return NGX_CONF_OK;
+}
+
+
 static void *
 ngx_http_slice_create_loc_conf(ngx_conf_t *cf)
 {
@@ -499,6 +688,7 @@ ngx_http_slice_create_loc_conf(ngx_conf_t *cf)
     }
 
     slcf->size = NGX_CONF_UNSET_SIZE;
+    slcf->read_a_heads = (float) NGX_CONF_UNSET;
 
     return slcf;
 }
@@ -511,6 +701,13 @@ ngx_http_slice_merge_loc_conf(ngx_conf_t *cf, void *pa
     ngx_http_slice_loc_conf_t *conf = child;
 
     ngx_conf_merge_size_value(conf->size, prev->size, 0);
+    ngx_conf_merge_value(conf->read_a_heads, prev->read_a_heads, 0.0);
+
+    if (conf->read_a_heads < 0.0) {
+        ngx_conf_log_error(NGX_LOG_EMERG, cf, 0, "read a head must be >= 0");
+        return NGX_CONF_ERROR;
+    }
+
 
     return NGX_CONF_OK;
 }
