--- server/upload-file.c.orig	2021-12-09 05:24:45 UTC
+++ server/upload-file.c
@@ -2234,7 +2234,7 @@ out:
         /* Set keepalive to 0. This will cause evhtp to close the
          * connection after sending the reply.
          */
-        req->keepalive = 0;
+	evhtp_request_set_keepalive(req, 0);
 
         fsm->state = RECV_ERROR;
     }
@@ -2545,8 +2545,8 @@ upload_headers_cb (evhtp_request_t *req, evhtp_headers
     }
 
     /* Set up per-request hooks, so that we can read file data piece by piece. */
-    evhtp_set_hook (&req->hooks, evhtp_hook_on_read, upload_read_cb, fsm);
-    evhtp_set_hook (&req->hooks, evhtp_hook_on_request_fini, upload_finish_cb, fsm);
+    evhtp_request_set_hook (req, evhtp_hook_on_read, upload_read_cb, fsm);
+    evhtp_request_set_hook (req, evhtp_hook_on_request_fini, upload_finish_cb, fsm);
     /* Set arg for upload_cb or update_cb. */
     req->cbarg = fsm;
 
@@ -2561,7 +2561,7 @@ err:
     /* Set keepalive to 0. This will cause evhtp to close the
      * connection after sending the reply.
      */
-    req->keepalive = 0;
+	  evhtp_request_set_keepalive(req, 0);
     send_error_reply (req, error_code, err_msg);
 
     g_free (repo_id);
@@ -2662,32 +2662,32 @@ upload_file_init (evhtp_t *htp, const char *http_temp_
     g_free (cluster_shared_dir);
 
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
 
     /* cb = evhtp_set_regex_cb (htp, "^/upload-blks-aj/.*", upload_blks_ajax_cb, NULL); */
     /* evhtp_set_hook(&cb->hooks, evhtp_hook_on_headers, upload_headers_cb, NULL); */
 
     cb = evhtp_set_regex_cb (htp, "^/upload-aj/.*", upload_ajax_cb, NULL);
-    evhtp_set_hook(&cb->hooks, evhtp_hook_on_headers, upload_headers_cb, NULL);
+    evhtp_callback_set_hook(cb, evhtp_hook_on_headers, upload_headers_cb, NULL);
 
     cb = evhtp_set_regex_cb (htp, "^/update-api/.*", update_api_cb, NULL);
-    evhtp_set_hook(&cb->hooks, evhtp_hook_on_headers, upload_headers_cb, NULL);
+    evhtp_callback_set_hook(cb, evhtp_hook_on_headers, upload_headers_cb, NULL);
 
     cb = evhtp_set_regex_cb (htp, "^/update-blks-api/.*", update_blks_api_cb, NULL);
-    evhtp_set_hook(&cb->hooks, evhtp_hook_on_headers, upload_headers_cb, NULL);
+    evhtp_callback_set_hook(cb, evhtp_hook_on_headers, upload_headers_cb, NULL);
 
     /* cb = evhtp_set_regex_cb (htp, "^/update-blks-aj/.*", update_blks_ajax_cb, NULL); */
     /* evhtp_set_hook(&cb->hooks, evhtp_hook_on_headers, upload_headers_cb, NULL); */
 
     cb = evhtp_set_regex_cb (htp, "^/update-aj/.*", update_ajax_cb, NULL);
-    evhtp_set_hook(&cb->hooks, evhtp_hook_on_headers, upload_headers_cb, NULL);
+    evhtp_callback_set_hook(cb, evhtp_hook_on_headers, upload_headers_cb, NULL);
 
     evhtp_set_regex_cb (htp, "^/upload_progress.*", upload_progress_cb, NULL);
 
