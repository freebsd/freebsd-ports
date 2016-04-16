Fix apache24-2.4.20 scoreboard, see discussion
http://mail-archives.apache.org/mod_mbox/httpd-dev/201604.mbox/browser

Patch based on http://home.apache.org/~ylavic/patches/scoreboard-2.4.18.diff

Index: server/scoreboard.c
===================================================================
--- server/scoreboard.c.orig	2016-03-02 13:22:07 UTC
+++ server/scoreboard.c
@@ -464,22 +464,18 @@ static int update_child_status_internal(
 {
     int old_status;
     worker_score *ws;
-    process_score *ps;
     int mpm_generation;
 
     ws = &ap_scoreboard_image->servers[child_num][thread_num];
     old_status = ws->status;
-    if (status >= 0) {
-        ws->status = status;
-        
-        ps = &ap_scoreboard_image->parent[child_num];
-        
-        if (status == SERVER_READY
-            && old_status == SERVER_STARTING) {
-            ws->thread_num = child_num * thread_limit + thread_num;
-            ap_mpm_query(AP_MPMQ_GENERATION, &mpm_generation);
-            ps->generation = mpm_generation;
-        }
+    ws->status = status;
+    
+    if (status == SERVER_READY
+        && old_status == SERVER_STARTING) {
+        process_score *ps = &ap_scoreboard_image->parent[child_num];
+        ws->thread_num = child_num * thread_limit + thread_num;
+        ap_mpm_query(AP_MPMQ_GENERATION, &mpm_generation);
+        ps->generation = mpm_generation;
     }
 
     if (ap_extended_status) {
@@ -497,46 +493,42 @@ static int update_child_status_internal(
             ws->conn_bytes = 0;
             ws->last_used = apr_time_now();
         }
-        if (status == SERVER_READY) {
-            ws->client[0]='\0';
-            ws->vhost[0]='\0';
-            ws->request[0]='\0';
-            ws->protocol[0]='\0';
+
+        if (descr) {
+            apr_cpystrn(ws->request, descr, sizeof(ws->request));
         }
-        else {
-            if (descr) {
-                apr_cpystrn(ws->request, descr, sizeof(ws->request));
-            }
-            else if (r) {
-                copy_request(ws->request, sizeof(ws->request), r);
-            }
-            if (r) {
-                if (!(val = ap_get_useragent_host(r, REMOTE_NOLOOKUP, NULL)))
-                    apr_cpystrn(ws->client, r->useragent_ip, sizeof(ws->client));
-                else
-                    apr_cpystrn(ws->client, val, sizeof(ws->client));
-            }
-            else if (c) {
-                if (!(val = ap_get_remote_host(c, c->base_server->lookup_defaults,
-                                               REMOTE_NOLOOKUP, NULL)))
-                    apr_cpystrn(ws->client, c->client_ip, sizeof(ws->client));
-                else
-                    apr_cpystrn(ws->client, val, sizeof(ws->client));
-            }
-            if (s) {
-                if (c) {
-                    apr_snprintf(ws->vhost, sizeof(ws->vhost), "%s:%d",
-                                 s->server_hostname, c->local_addr->port);
-                }
-                else {
-                    apr_cpystrn(ws->vhost, s->server_hostname, sizeof(ws->vhost));
-                }
-            }
+        else if (r) {
+            copy_request(ws->request, sizeof(ws->request), r);
+        }
+
+        if (r) {
+            if (!(val = ap_get_useragent_host(r, REMOTE_NOLOOKUP, NULL)))
+                apr_cpystrn(ws->client, r->useragent_ip, sizeof(ws->client));
+            else
+                apr_cpystrn(ws->client, val, sizeof(ws->client));
+        }
+        else if (c) {
+            if (!(val = ap_get_remote_host(c, c->base_server->lookup_defaults,
+                                           REMOTE_NOLOOKUP, NULL)))
+                apr_cpystrn(ws->client, c->client_ip, sizeof(ws->client));
+            else
+                apr_cpystrn(ws->client, val, sizeof(ws->client));
+        }
+
+        if (s) {
             if (c) {
-                val = ap_get_protocol(c);
-                apr_cpystrn(ws->protocol, val, sizeof(ws->protocol));
+                apr_snprintf(ws->vhost, sizeof(ws->vhost), "%s:%d",
+                             s->server_hostname, c->local_addr->port);
+            }
+            else {
+                apr_cpystrn(ws->vhost, s->server_hostname, sizeof(ws->vhost));
             }
         }
+
+        if (c) {
+            val = ap_get_protocol(c);
+            apr_cpystrn(ws->protocol, val, sizeof(ws->protocol));
+        }
     }
 
     return old_status;
