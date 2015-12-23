### Description: Commit 67ed0bc caused ports to break, this
### patch will revert the commits until a proper fix is created.
### Issue ID: https://github.com/ellzey/libevhtp/issues/201
### https://github.com/ellzey/libevhtp/commit/67ed0bce433655dfeab65b797279dd167b394feb
--- evhtp.c.orig	2015-11-02 23:01:53 UTC
+++ evhtp.c
@@ -1673,12 +1673,10 @@ check_proto:
                                          evhtp_header_new("Connection", "close", 0, 0));
             }
 
-#if 0
-            if (!out_len && !evhtp_header_find(request->headers_out, "Content-Length")) {
+            if (!evhtp_header_find(request->headers_out, "Content-Length")) {
                 evhtp_headers_add_header(request->headers_out,
                                          evhtp_header_new("Content-Length", "0", 0, 0));
             }
-#endif
 
             break;
         case EVHTP_PROTO_10:
@@ -2356,7 +2354,7 @@ evhtp_connection_pause(evhtp_connection_
 
     c->paused = 1;
 
-    bufferevent_disable(c->bev, EV_READ | EV_WRITE);
+    bufferevent_disable(c->bev, EV_READ);
 
     return;
 }
