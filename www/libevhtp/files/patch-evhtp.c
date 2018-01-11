--- evhtp.c.orig	2017-12-06 22:34:23 UTC
+++ evhtp.c
@@ -2373,15 +2373,15 @@ htp__connection_writecb_(struct bufferevent * bev, voi
         return;
     }
 
-    /* run user-hook for on_write callback before further analysis */
-    htp__hook_connection_write_(conn);
-
     /* connection is in a paused state, no further processing yet */
     if ((conn->flags & EVHTP_CONN_FLAG_PAUSED))
     {
         return;
     }
 
+    /* run user-hook for on_write callback before further analysis */
+    htp__hook_connection_write_(conn);
+
     if (conn->flags & EVHTP_CONN_FLAG_WAITING)
     {
         HTP_FLAG_OFF(conn, EVHTP_CONN_FLAG_WAITING);
@@ -3043,7 +3043,7 @@ evhtp_connection_pause(evhtp_connection_t * c)
 
     HTP_FLAG_ON(c, EVHTP_CONN_FLAG_PAUSED);
 
-    bufferevent_disable(c->bev, EV_READ | EV_WRITE);
+    bufferevent_disable(c->bev, EV_READ);
 
     return;
 }
