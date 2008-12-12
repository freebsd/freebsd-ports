--- src/daemon.c.orig	Sat Aug 30 03:49:46 2008
+++ src/daemon.c	Mon Sep  1 00:46:09 2008
@@ -1613,7 +1613,7 @@
   struct sockaddr_in accepted;
   #endif
 
-  EXIM_SOCKLEN_T len = sizeof(accepted);
+  EXIM_SOCKLEN_T len;
   pid_t pid;
 
   /* This code is placed first in the loop, so that it gets obeyed at the
@@ -1808,6 +1808,7 @@
           {
           if (FD_ISSET(listen_sockets[sk], &select_listen))
             {
+            len = sizeof(accepted);
             accept_socket = accept(listen_sockets[sk],
               (struct sockaddr *)&accepted, &len);
             FD_CLR(listen_sockets[sk], &select_listen);
