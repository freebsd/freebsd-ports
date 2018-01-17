--- server/http-server.c.orig	2018-01-03 02:47:07 UTC
+++ server/http-server.c
@@ -2122,7 +2122,7 @@ http_server_run (void *arg)
 
     http_request_init (server);
 
-    evhtp_use_threads (priv->evhtp, NULL, server->worker_threads, NULL);
+    evhtp_use_threads_wexit (priv->evhtp, NULL, NULL, server->worker_threads, NULL);
 
     struct timeval tv;
     tv.tv_sec = CLEANING_INTERVAL_SEC;
