--- server/upload-file.c.orig	2017-11-03 09:11:19 UTC
+++ server/upload-file.c
@@ -2048,12 +2048,12 @@ upload_read_cb (evhtp_request_t *req, evbuf_t *buf, vo
 out:
     if (res != EVHTP_RES_OK) {
         /* Don't receive any data before the connection is closed. */
-        evhtp_request_pause (req);
+	bufferevent_disable(evhtp_request_get_bev(req), EV_READ);
 
         /* Set keepalive to 0. This will cause evhtp to close the
          * connection after sending the reply.
          */
-        req->keepalive = 0;
+	evhtp_request_set_keepalive(req, 0);
 
         fsm->state = RECV_ERROR;
     }
@@ -2254,8 +2254,8 @@ upload_headers_cb (evhtp_request_t *req, evhtp_headers
     }
 
     /* Set up per-request hooks, so that we can read file data piece by piece. */
-    evhtp_set_hook (&req->hooks, evhtp_hook_on_read, upload_read_cb, fsm);
-    evhtp_set_hook (&req->hooks, evhtp_hook_on_request_fini, upload_finish_cb, fsm);
+    evhtp_request_set_hook (req, evhtp_hook_on_read, upload_read_cb, fsm);
+    evhtp_request_set_hook (req, evhtp_hook_on_request_fini, upload_finish_cb, fsm);
     /* Set arg for upload_cb or update_cb. */
     req->cbarg = fsm;
 
@@ -2265,12 +2265,12 @@ upload_headers_cb (evhtp_request_t *req, evhtp_headers
 
 err:
     /* Don't receive any data before the connection is closed. */
-    evhtp_request_pause (req);
+    bufferevent_disable(evhtp_request_get_bev(req), EV_READ);
 
     /* Set keepalive to 0. This will cause evhtp to close the
      * connection after sending the reply.
      */
-    req->keepalive = 0;
+    evhtp_request_set_keepalive(req, 0);
     send_error_reply (req, EVHTP_RES_BADREQ, err_msg);
 
     g_free (repo_id);
@@ -2339,38 +2339,38 @@ upload_file_init (evhtp_t *htp, const char *http_temp_
 
     cb = evhtp_set_regex_cb (htp, "^/upload/.*", upload_cb, NULL);
     /* upload_headers_cb() will be called after evhtp parsed all http headers. */
-    evhtp_set_hook(&cb->hooks, evhtp_hook_on_headers, upload_headers_cb, NULL);
+    evhtp_callback_set_hook(cb, evhtp_hook_on_headers, upload_headers_cb, NULL);
 
     cb = evhtp_set_regex_cb (htp, "^/upload-api/.*", upload_api_cb, NULL);
-    evhtp_set_hook(&cb->hooks, evhtp_hook_on_headers, upload_headers_cb, NULL);
+    evhtp_callback_set_hook(cb, evhtp_hook_on_headers, upload_headers_cb, NULL);
 
     cb = evhtp_set_regex_cb (htp, "^/upload-raw-blks-api/.*",
                              upload_raw_blks_api_cb, NULL);
-    evhtp_set_hook(&cb->hooks, evhtp_hook_on_headers, upload_headers_cb, NULL);
+    evhtp_callback_set_hook(cb, evhtp_hook_on_headers, upload_headers_cb, NULL);
 
     cb = evhtp_set_regex_cb (htp, "^/upload-blks-api/.*", upload_blks_api_cb, NULL);
-    evhtp_set_hook(&cb->hooks, evhtp_hook_on_headers, upload_headers_cb, NULL);
+    evhtp_callback_set_hook(cb, evhtp_hook_on_headers, upload_headers_cb, NULL);
 
     cb = evhtp_set_regex_cb (htp, "^/upload-blks-aj/.*", upload_blks_ajax_cb, NULL);
-    evhtp_set_hook(&cb->hooks, evhtp_hook_on_headers, upload_headers_cb, NULL);
+    evhtp_callback_set_hook(cb, evhtp_hook_on_headers, upload_headers_cb, NULL);
 
     cb = evhtp_set_regex_cb (htp, "^/upload-aj/.*", upload_ajax_cb, NULL);
-    evhtp_set_hook(&cb->hooks, evhtp_hook_on_headers, upload_headers_cb, NULL);
+    evhtp_callback_set_hook(cb, evhtp_hook_on_headers, upload_headers_cb, NULL);
 
     cb = evhtp_set_regex_cb (htp, "^/update/.*", update_cb, NULL);
-    evhtp_set_hook(&cb->hooks, evhtp_hook_on_headers, upload_headers_cb, NULL);
+    evhtp_callback_set_hook(cb, evhtp_hook_on_headers, upload_headers_cb, NULL);
 
     cb = evhtp_set_regex_cb (htp, "^/update-api/.*", update_api_cb, NULL);
-    evhtp_set_hook(&cb->hooks, evhtp_hook_on_headers, upload_headers_cb, NULL);
+    evhtp_callback_set_hook(cb, evhtp_hook_on_headers, upload_headers_cb, NULL);
 
     cb = evhtp_set_regex_cb (htp, "^/update-blks-api/.*", update_blks_api_cb, NULL);
-    evhtp_set_hook(&cb->hooks, evhtp_hook_on_headers, upload_headers_cb, NULL);
+    evhtp_callback_set_hook(cb, evhtp_hook_on_headers, upload_headers_cb, NULL);
 
     cb = evhtp_set_regex_cb (htp, "^/update-blks-aj/.*", update_blks_ajax_cb, NULL);
-    evhtp_set_hook(&cb->hooks, evhtp_hook_on_headers, upload_headers_cb, NULL);
+    evhtp_callback_set_hook(cb, evhtp_hook_on_headers, upload_headers_cb, NULL);
 
     cb = evhtp_set_regex_cb (htp, "^/update-aj/.*", update_ajax_cb, NULL);
-    evhtp_set_hook(&cb->hooks, evhtp_hook_on_headers, upload_headers_cb, NULL);
+    evhtp_callback_set_hook(cb, evhtp_hook_on_headers, upload_headers_cb, NULL);
 
     evhtp_set_regex_cb (htp, "^/upload_progress.*", upload_progress_cb, NULL);
 
