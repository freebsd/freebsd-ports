--- ../drizzle-nginx-module-0.1.8/src/ngx_http_drizzle_util.c.orig	2015-05-28 02:39:19.661703000 +0300
+++ ../drizzle-nginx-module-0.1.8/src/ngx_http_drizzle_util.c	2015-05-28 02:41:12.655554000 +0300
@@ -114,10 +114,8 @@
         u->resolved->ctx = NULL;
     }
 
-    if (u->state && u->state->response_sec) {
-        tp = ngx_timeofday();
-        u->state->response_sec = tp->sec - u->state->response_sec;
-        u->state->response_msec = tp->msec - u->state->response_msec;
+    if (u->state && u->state->response_time) {
+        u->state->response_time = ngx_current_msec - u->state->response_time;
 
         if (u->pipe) {
             u->state->response_length = u->pipe->read_length;
@@ -588,10 +586,8 @@
 
     r->connection->log->action = "connecting to upstream";
 
-    if (u->state && u->state->response_sec) {
-        tp = ngx_timeofday();
-        u->state->response_sec = tp->sec - u->state->response_sec;
-        u->state->response_msec = tp->msec - u->state->response_msec;
+    if (u->state && u->state->response_time) {
+        u->state->response_time = ngx_current_msec - u->state->response_time;
     }
 
     u->state = ngx_array_push(r->upstream_states);
@@ -603,9 +599,7 @@
 
     ngx_memzero(u->state, sizeof(ngx_http_upstream_state_t));
 
-    tp = ngx_timeofday();
-    u->state->response_sec = tp->sec;
-    u->state->response_msec = tp->msec;
+    u->state->response_time = ngx_current_msec - u->state->response_time;
 
     rc = ngx_event_connect_peer(&u->peer);
 
