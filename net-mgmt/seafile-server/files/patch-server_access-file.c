--- server/access-file.c.orig	2018-01-04 08:07:23 UTC
+++ server/access-file.c
@@ -618,7 +618,7 @@ do_file(evhtp_request_t *req, SeafRepo *repo, const ch
     /* Block any new request from this connection before finish
      * handling this request.
      */
-    evhtp_request_pause (req);
+    bufferevent_disable(bev, EV_READ);
 
     /* Kick start data transfer by sending out http headers. */
     evhtp_send_reply_start(req, EVHTP_RES_OK);
@@ -967,7 +967,7 @@ do_file_range (evhtp_request_t *req, SeafRepo *repo, c
     /* Block any new request from this connection before finish
      * handling this request.
      */
-    evhtp_request_pause (req);
+    bufferevent_disable(bev, EV_READ);
 
     /* Kick start data transfer by sending out http headers. */
     evhtp_send_reply_start(req, EVHTP_RES_PARTIAL);
@@ -1037,7 +1037,7 @@ start_download_zip_file (evhtp_request_t *req, const c
     /* Block any new request from this connection before finish
      * handling this request.
      */
-    evhtp_request_pause (req);
+    bufferevent_disable(bev, EV_READ);
 
     /* Kick start data transfer by sending out http headers. */
     evhtp_send_reply_start(req, EVHTP_RES_OK);
@@ -1365,7 +1365,7 @@ do_block(evhtp_request_t *req, SeafRepo *repo, const c
     /* Block any new request from this connection before finish
      * handling this request.
      */
-    evhtp_request_pause (req);
+    bufferevent_disable(bev, EV_READ);
 
     /* Kick start data transfer by sending out http headers. */
     evhtp_send_reply_start(req, EVHTP_RES_OK);
