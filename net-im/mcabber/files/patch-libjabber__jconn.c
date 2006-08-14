--- ./libjabber/jconn.c.orig	Sun Aug 13 23:01:59 2006
+++ ./libjabber/jconn.c	Mon Aug 14 10:15:47 2006
@@ -164,6 +164,9 @@
     }
     change_socket_to_blocking(j->fd);
 
+    /* XXX why do we need this?? */
+    sleep (1);
+
     j->state = JCONN_STATE_CONNECTED;
     STATE_EVT(JCONN_STATE_CONNECTED)
 
