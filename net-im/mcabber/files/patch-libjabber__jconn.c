--- ./libjabber/jconn.c.orig	Sat Dec 16 21:05:39 2006
+++ ./libjabber/jconn.c	Sat Jan 13 03:02:55 2007
@@ -164,6 +164,9 @@
     }
     change_socket_to_blocking(j->fd);
 
+    /* XXX why do we need this?? */
+    sleep (1);
+
     j->state = JCONN_STATE_CONNECTED;
     STATE_EVT(JCONN_STATE_CONNECTED)
 
