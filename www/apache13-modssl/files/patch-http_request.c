--- src/main/http_request.c.bak	Wed Apr 28 20:58:42 2004
+++ src/main/http_request.c	Mon Jun 14 17:11:06 2004
@@ -1056,7 +1056,7 @@
      */
     if ((r->status != HTTP_NOT_MODIFIED) && (r->status != HTTP_NO_CONTENT)
         && !ap_status_drops_connection(r->status)
-        && r->connection && (r->connection->keepalive > 0)) {
+        && r->connection && (r->connection->keepalive != -1)) {
 
         (void) ap_discard_request_body(r);
     }
