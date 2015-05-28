--- ../FRiCKLE-ngx_postgres-49855a0/src/ngx_postgres_util.c.orig	2015-05-28 02:58:30.914607000 +0300
+++ ../FRiCKLE-ngx_postgres-49855a0/src/ngx_postgres_util.c	2015-05-28 02:59:57.539743000 +0300
@@ -61,10 +61,8 @@
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
