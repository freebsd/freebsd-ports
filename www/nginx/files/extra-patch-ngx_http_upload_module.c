--- ../nginx_upload_module-2.2.0/ngx_http_upload_module.c.orig	2010-09-27 20:54:15.000000000 +0200
+++ ../nginx_upload_module-2.2.0/ngx_http_upload_module.c	2013-02-21 22:32:08.000000000 +0100
@@ -233,6 +233,17 @@
     unsigned int        raw_input:1;
 } ngx_http_upload_ctx_t;
 
+static void ngx_http_read_client_request_body_handler(ngx_http_request_t *r);
+static ngx_int_t ngx_http_do_read_client_request_body(ngx_http_request_t *r);
+
+static ngx_int_t ngx_http_write_request_body(ngx_http_request_t *r);
+static ngx_int_t ngx_http_request_body_filter(ngx_http_request_t *r, ngx_chain_t *in);
+
+static ngx_int_t ngx_http_request_body_length_filter(ngx_http_request_t *r, ngx_chain_t *in);
+static ngx_int_t ngx_http_request_body_chunked_filter(ngx_http_request_t *r, ngx_chain_t *in);
+
+static ngx_int_t ngx_http_request_body_save_filter(ngx_http_request_t *r, ngx_chain_t *in);
+
 static ngx_int_t ngx_http_upload_handler(ngx_http_request_t *r);
 static ngx_int_t ngx_http_upload_body_handler(ngx_http_request_t *r);
 
@@ -2523,6 +2534,534 @@
     return NGX_CONF_OK;
 } /* }}} */
 
+static ngx_int_t
+ngx_http_write_request_body(ngx_http_request_t *r)
+{
+    ssize_t                    n;
+    ngx_chain_t               *cl;
+    ngx_temp_file_t           *tf;
+    ngx_http_request_body_t   *rb;
+    ngx_http_core_loc_conf_t  *clcf;
+
+    rb = r->request_body;
+
+    ngx_log_debug1(NGX_LOG_DEBUG_HTTP, r->connection->log, 0,
+                   "http write client request body, bufs %p", rb->bufs);
+
+    if (rb->temp_file == NULL) {
+        tf = ngx_pcalloc(r->pool, sizeof(ngx_temp_file_t));
+        if (tf == NULL) {
+            return NGX_ERROR;
+        }
+
+        clcf = ngx_http_get_module_loc_conf(r, ngx_http_core_module);
+
+        tf->file.fd = NGX_INVALID_FILE;
+        tf->file.log = r->connection->log;
+        tf->path = clcf->client_body_temp_path;
+        tf->pool = r->pool;
+        tf->warn = "a client request body is buffered to a temporary file";
+        tf->log_level = r->request_body_file_log_level;
+        tf->persistent = r->request_body_in_persistent_file;
+        tf->clean = r->request_body_in_clean_file;
+
+        if (r->request_body_file_group_access) {
+            tf->access = 0660;
+        }
+
+        rb->temp_file = tf;
+
+        if (rb->bufs == NULL) {
+            /* empty body with r->request_body_in_file_only */
+
+            if (ngx_create_temp_file(&tf->file, tf->path, tf->pool,
+                                     tf->persistent, tf->clean, tf->access)
+                != NGX_OK)
+            {
+                return NGX_ERROR;
+            }
+
+            return NGX_OK;
+        }
+    }
+
+    if (rb->bufs == NULL) {
+        return NGX_OK;
+    }
+
+    n = ngx_write_chain_to_temp_file(rb->temp_file, rb->bufs);
+
+    /* TODO: n == 0 or not complete and level event */
+
+    if (n == NGX_ERROR) {
+        return NGX_ERROR;
+    }
+
+    rb->temp_file->offset += n;
+
+    /* mark all buffers as written */
+
+    for (cl = rb->bufs; cl; cl = cl->next) {
+        cl->buf->pos = cl->buf->last;
+    }
+
+    rb->bufs = NULL;
+
+    return NGX_OK;
+}
+
+static ngx_int_t
+ngx_http_request_body_filter(ngx_http_request_t *r, ngx_chain_t *in)
+{
+    if (r->headers_in.chunked) {
+        return ngx_http_request_body_chunked_filter(r, in);
+
+    } else {
+        return ngx_http_request_body_length_filter(r, in);
+    }
+}
+
+static ngx_int_t
+ngx_http_request_body_save_filter(ngx_http_request_t *r, ngx_chain_t *in)
+{
+#if (NGX_DEBUG)
+    ngx_chain_t               *cl;
+#endif
+    ngx_http_request_body_t   *rb;
+
+    rb = r->request_body;
+
+#if (NGX_DEBUG)
+
+    for (cl = rb->bufs; cl; cl = cl->next) {
+        ngx_log_debug7(NGX_LOG_DEBUG_EVENT, r->connection->log, 0,
+                       "http body old buf t:%d f:%d %p, pos %p, size: %z "
+                       "file: %O, size: %z",
+                       cl->buf->temporary, cl->buf->in_file,
+                       cl->buf->start, cl->buf->pos,
+                       cl->buf->last - cl->buf->pos,
+                       cl->buf->file_pos,
+                       cl->buf->file_last - cl->buf->file_pos);
+    }
+
+    for (cl = in; cl; cl = cl->next) {
+        ngx_log_debug7(NGX_LOG_DEBUG_EVENT, r->connection->log, 0,
+                       "http body new buf t:%d f:%d %p, pos %p, size: %z "
+                       "file: %O, size: %z",
+                       cl->buf->temporary, cl->buf->in_file,
+                       cl->buf->start, cl->buf->pos,
+                       cl->buf->last - cl->buf->pos,
+                       cl->buf->file_pos,
+                       cl->buf->file_last - cl->buf->file_pos);
+    }
+
+#endif
+
+    /* TODO: coalesce neighbouring buffers */
+
+    if (ngx_chain_add_copy(r->pool, &rb->bufs, in) != NGX_OK) {
+        return NGX_HTTP_INTERNAL_SERVER_ERROR;
+    }
+
+    return NGX_OK;
+}
+
+
+static ngx_int_t
+ngx_http_request_body_length_filter(ngx_http_request_t *r, ngx_chain_t *in)
+{
+    size_t                     size;
+    ngx_int_t                  rc;
+    ngx_buf_t                 *b;
+    ngx_chain_t               *cl, *tl, *out, **ll;
+    ngx_http_request_body_t   *rb;
+
+    rb = r->request_body;
+
+    if (rb->rest == -1) {
+        ngx_log_debug0(NGX_LOG_DEBUG_HTTP, r->connection->log, 0,
+                       "http request body content length filter");
+
+        rb->rest = r->headers_in.content_length_n;
+    }
+
+    out = NULL;
+    ll = &out;
+
+    for (cl = in; cl; cl = cl->next) {
+
+        tl = ngx_chain_get_free_buf(r->pool, &rb->free);
+        if (tl == NULL) {
+            return NGX_HTTP_INTERNAL_SERVER_ERROR;
+        }
+
+        b = tl->buf;
+
+        ngx_memzero(b, sizeof(ngx_buf_t));
+
+        b->temporary = 1;
+        b->tag = (ngx_buf_tag_t) &ngx_http_read_client_request_body;
+        b->start = cl->buf->start;
+        b->pos = cl->buf->pos;
+        b->last = cl->buf->last;
+        b->end = cl->buf->end;
+
+        size = cl->buf->last - cl->buf->pos;
+
+        if ((off_t) size < rb->rest) {
+            cl->buf->pos = cl->buf->last;
+            rb->rest -= size;
+
+        } else {
+            cl->buf->pos += rb->rest;
+            rb->rest = 0;
+            b->last = cl->buf->pos;
+            b->last_buf = 1;
+        }
+
+        *ll = tl;
+        ll = &tl->next;
+    }
+
+    rc = ngx_http_request_body_save_filter(r, out);
+
+    ngx_chain_update_chains(r->pool, &rb->free, &rb->busy, &out,
+                            (ngx_buf_tag_t) &ngx_http_read_client_request_body);
+
+    return rc;
+}
+
+static ngx_int_t
+ngx_http_request_body_chunked_filter(ngx_http_request_t *r, ngx_chain_t *in)
+{
+    size_t                     size;
+    ngx_int_t                  rc;
+    ngx_buf_t                 *b;
+    ngx_chain_t               *cl, *out, *tl, **ll;
+    ngx_http_request_body_t   *rb;
+    ngx_http_core_loc_conf_t  *clcf;
+
+    rb = r->request_body;
+
+    if (rb->rest == -1) {
+
+        ngx_log_debug0(NGX_LOG_DEBUG_HTTP, r->connection->log, 0,
+                       "http request body chunked filter");
+
+        rb->chunked = ngx_pcalloc(r->pool, sizeof(ngx_http_chunked_t));
+        if (rb->chunked == NULL) {
+            return NGX_HTTP_INTERNAL_SERVER_ERROR;
+        }
+
+        r->headers_in.content_length_n = 0;
+        rb->rest = 3;
+    }
+
+    out = NULL;
+    ll = &out;
+
+    for (cl = in; cl; cl = cl->next) {
+
+        for ( ;; ) {
+
+            ngx_log_debug7(NGX_LOG_DEBUG_EVENT, r->connection->log, 0,
+                           "http body chunked buf "
+                           "t:%d f:%d %p, pos %p, size: %z file: %O, size: %z",
+                           cl->buf->temporary, cl->buf->in_file,
+                           cl->buf->start, cl->buf->pos,
+                           cl->buf->last - cl->buf->pos,
+                           cl->buf->file_pos,
+                           cl->buf->file_last - cl->buf->file_pos);
+
+            rc = ngx_http_parse_chunked(r, cl->buf, rb->chunked);
+
+            if (rc == NGX_OK) {
+
+                /* a chunk has been parsed successfully */
+
+                clcf = ngx_http_get_module_loc_conf(r, ngx_http_core_module);
+
+                if (clcf->client_max_body_size
+                    && clcf->client_max_body_size
+                       < r->headers_in.content_length_n + rb->chunked->size)
+                {
+                    ngx_log_error(NGX_LOG_ERR, r->connection->log, 0,
+                                  "client intended to send too large chunked "
+                                  "body: %O bytes",
+                                  r->headers_in.content_length_n
+                                  + rb->chunked->size);
+
+                    r->lingering_close = 1;
+
+                    return NGX_HTTP_REQUEST_ENTITY_TOO_LARGE;
+                }
+
+                tl = ngx_chain_get_free_buf(r->pool, &rb->free);
+                if (tl == NULL) {
+                    return NGX_HTTP_INTERNAL_SERVER_ERROR;
+                }
+
+                b = tl->buf;
+
+                ngx_memzero(b, sizeof(ngx_buf_t));
+
+                b->temporary = 1;
+                b->tag = (ngx_buf_tag_t) &ngx_http_read_client_request_body;
+                b->start = cl->buf->start;
+                b->pos = cl->buf->pos;
+                b->last = cl->buf->last;
+                b->end = cl->buf->end;
+
+                *ll = tl;
+                ll = &tl->next;
+
+                size = cl->buf->last - cl->buf->pos;
+
+                if ((off_t) size > rb->chunked->size) {
+                   cl->buf->pos += rb->chunked->size;
+                    r->headers_in.content_length_n += rb->chunked->size;
+                    rb->chunked->size = 0;
+
+                } else {
+                    rb->chunked->size -= size;
+                    r->headers_in.content_length_n += size;
+                    cl->buf->pos = cl->buf->last;
+                }
+
+                b->last = cl->buf->pos;
+
+                continue;
+            }
+
+            if (rc == NGX_DONE) {
+
+                /* a whole response has been parsed successfully */
+
+                rb->rest = 0;
+
+                tl = ngx_chain_get_free_buf(r->pool, &rb->free);
+                if (tl == NULL) {
+                    return NGX_HTTP_INTERNAL_SERVER_ERROR;
+                }
+
+                b = tl->buf;
+
+                ngx_memzero(b, sizeof(ngx_buf_t));
+
+                b->last_buf = 1;
+
+                *ll = tl;
+                ll = &tl->next;
+
+                break;
+            }
+
+            if (rc == NGX_AGAIN) {
+
+                /* set rb->rest, amount of data we want to see next time */
+
+                rb->rest = rb->chunked->length;
+
+                break;
+            }
+
+            /* invalid */
+
+            ngx_log_error(NGX_LOG_ERR, r->connection->log, 0,
+                          "client sent invalid chunked body");
+
+            return NGX_HTTP_BAD_REQUEST;
+        }
+    }
+
+    rc = ngx_http_request_body_save_filter(r, out);
+
+    ngx_chain_update_chains(r->pool, &rb->free, &rb->busy, &out,
+                            (ngx_buf_tag_t) &ngx_http_read_client_request_body);
+
+    return rc;
+}
+
+static ngx_int_t
+ngx_http_do_read_client_request_body(ngx_http_request_t *r)
+{
+    off_t                      rest;
+    size_t                     size;
+    ssize_t                    n;
+    ngx_int_t                  rc;
+    ngx_buf_t                 *b;
+    ngx_chain_t               *cl, out;
+    ngx_connection_t          *c;
+    ngx_http_request_body_t   *rb;
+    ngx_http_core_loc_conf_t  *clcf;
+
+    c = r->connection;
+    rb = r->request_body;
+
+    ngx_log_debug0(NGX_LOG_DEBUG_HTTP, c->log, 0,
+                   "http read client request body");
+
+    for ( ;; ) {
+        for ( ;; ) {
+            if (rb->buf->last == rb->buf->end) {
+
+                /* pass buffer to request body filter chain */
+
+                out.buf = rb->buf;
+                out.next = NULL;
+
+                rc = ngx_http_request_body_filter(r, &out);
+
+                if (rc != NGX_OK) {
+                    return rc;
+                }
+
+                /* write to file */
+
+                if (ngx_http_write_request_body(r) != NGX_OK) {
+                    return NGX_HTTP_INTERNAL_SERVER_ERROR;
+                }
+
+                /* update chains */
+
+                rc = ngx_http_request_body_filter(r, NULL);
+
+                if (rc != NGX_OK) {
+                    return rc;
+                }
+
+                if (rb->busy != NULL) {
+                    return NGX_HTTP_INTERNAL_SERVER_ERROR;
+                }
+
+                rb->buf->pos = rb->buf->start;
+                rb->buf->last = rb->buf->start;
+            }
+            size = rb->buf->end - rb->buf->last;
+            rest = rb->rest - (rb->buf->last - rb->buf->pos);
+
+            if ((off_t) size > rest) {
+                size = (size_t) rest;
+            }
+
+            n = c->recv(c, rb->buf->last, size);
+
+            ngx_log_debug1(NGX_LOG_DEBUG_HTTP, c->log, 0,
+                           "http client request body recv %z", n);
+
+            if (n == NGX_AGAIN) {
+                break;
+            }
+
+            if (n == 0) {
+                ngx_log_error(NGX_LOG_INFO, c->log, 0,
+                              "client prematurely closed connection");
+            }
+
+            if (n == 0 || n == NGX_ERROR) {
+                c->error = 1;
+                return NGX_HTTP_BAD_REQUEST;
+            }
+
+            rb->buf->last += n;
+            r->request_length += n;
+
+            if (n == rest) {
+                /* pass buffer to request body filter chain */
+
+                out.buf = rb->buf;
+                out.next = NULL;
+
+                rc = ngx_http_request_body_filter(r, &out);
+
+                if (rc != NGX_OK) {
+                    return rc;
+                }
+            }
+
+            if (rb->rest == 0) {
+                break;
+            }
+
+            if (rb->buf->last < rb->buf->end) {
+                break;
+            }
+        }
+
+        ngx_log_debug1(NGX_LOG_DEBUG_HTTP, c->log, 0,
+                       "http client request body rest %O", rb->rest);
+                      if (rb->rest == 0) {
+            break;
+        }
+
+        if (!c->read->ready) {
+            clcf = ngx_http_get_module_loc_conf(r, ngx_http_core_module);
+            ngx_add_timer(c->read, clcf->client_body_timeout);
+
+            if (ngx_handle_read_event(c->read, 0) != NGX_OK) {
+                return NGX_HTTP_INTERNAL_SERVER_ERROR;
+            }
+
+            return NGX_AGAIN;
+        }
+    }
+
+    if (c->read->timer_set) {
+        ngx_del_timer(c->read);
+    }
+
+    if (rb->temp_file || r->request_body_in_file_only) {
+
+        /* save the last part */
+
+        if (ngx_http_write_request_body(r) != NGX_OK) {
+            return NGX_HTTP_INTERNAL_SERVER_ERROR;
+        }
+
+        cl = ngx_chain_get_free_buf(r->pool, &rb->free);
+        if (cl == NULL) {
+            return NGX_HTTP_INTERNAL_SERVER_ERROR;
+        }
+
+        b = cl->buf;
+
+        ngx_memzero(b, sizeof(ngx_buf_t));
+
+        b->in_file = 1;
+        b->file_last = rb->temp_file->file.offset;
+        b->file = &rb->temp_file->file;
+
+        rb->bufs = cl;
+    }
+
+    r->read_event_handler = ngx_http_block_reading;
+
+    rb->post_handler(r);
+
+    return NGX_OK;
+}
+
+
+static void
+ngx_http_read_client_request_body_handler(ngx_http_request_t *r)
+{
+    ngx_int_t  rc;
+
+    if (r->connection->read->timedout) {
+        r->connection->timedout = 1;
+        ngx_http_finalize_request(r, NGX_HTTP_REQUEST_TIME_OUT);
+        return;
+    }
+
+    rc = ngx_http_do_read_client_request_body(r);
+
+    if (rc >= NGX_HTTP_SPECIAL_RESPONSE) {
+        ngx_http_finalize_request(r, rc);
+    }
+}
+
+
+
 ngx_int_t /* {{{ ngx_http_read_upload_client_request_body */
 ngx_http_read_upload_client_request_body(ngx_http_request_t *r) {
     ssize_t                    size, preread;
@@ -2625,9 +3164,9 @@
 
             /* the whole request body may be placed in r->header_in */
 
-            rb->to_write = rb->bufs;
-
-            r->read_event_handler = ngx_http_read_upload_client_request_body_handler;
+            rb->buf = r->header_in;
+            r->read_event_handler = ngx_http_read_client_request_body_handler;
+            r->write_event_handler = ngx_http_request_empty_handler;
 
             return ngx_http_do_read_upload_client_request_body(r);
         }
@@ -2684,7 +3223,7 @@
 
     *next = cl;
 
-    rb->to_write = rb->bufs;
+    /* rb->to_write = rb->bufs; */
 
     r->read_event_handler = ngx_http_read_upload_client_request_body_handler;
 
@@ -2766,7 +3305,7 @@
         for ( ;; ) {
             if (rb->buf->last == rb->buf->end) {
 
-                rc = ngx_http_process_request_body(r, rb->to_write);
+                rc = ngx_http_process_request_body(r, rb->bufs);
 
                 switch(rc) {
                     case NGX_OK:
@@ -2782,7 +3321,7 @@
                         return NGX_HTTP_INTERNAL_SERVER_ERROR;
                 }
 
-                rb->to_write = rb->bufs->next ? rb->bufs->next : rb->bufs;
+                /* rb->to_write = rb->bufs->next ? rb->bufs->next : rb->bufs; */
                 rb->buf->last = rb->buf->start;
             }
 
@@ -2874,7 +3413,7 @@
         ngx_del_timer(c->read);
     }
 
-    rc = ngx_http_process_request_body(r, rb->to_write);
+    rc = ngx_http_process_request_body(r, rb->bufs);
 
     switch(rc) {
         case NGX_OK:
