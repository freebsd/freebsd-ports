--- ./libvncserver/sockets.c.orig	2012-05-04 16:19:00.000000000 +0200
+++ ./libvncserver/sockets.c	2012-06-07 01:13:31.179964830 +0200
@@ -402,9 +402,9 @@
       rfbLogPerror("rfbProcessNewConnection: error in select");
       return FALSE;
     }
-    if (FD_ISSET(rfbScreen->listenSock, &listen_fds)) 
+    if (rfbScreen->listenSock >= 0 && FD_ISSET(rfbScreen->listenSock, &listen_fds))
       chosen_listen_sock = rfbScreen->listenSock;
-    if (FD_ISSET(rfbScreen->listen6Sock, &listen_fds)) 
+    if (rfbScreen->listen6Sock >= 0 && FD_ISSET(rfbScreen->listen6Sock, &listen_fds))
       chosen_listen_sock = rfbScreen->listen6Sock;
 
     if ((sock = accept(chosen_listen_sock,
