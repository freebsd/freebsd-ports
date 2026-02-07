--- ADMsmb.c.orig	Tue Oct  3 19:48:45 2006
+++ ADMsmb.c	Tue Oct  3 19:48:49 2006
@@ -139,7 +139,7 @@
     {
       usleep (100000);
 
-      if (recvfrom (socket_client, buffer2,sizeof(buffer2), 0, (struct sockaddr *) &sin_dst, &(int) longueur) != -1)
+      if (recvfrom (socket_client, buffer2,sizeof(buffer2), 0, (struct sockaddr *) &sin_dst, &longueur) != -1)
 	{         
 
 	  if (nmb2->rep_num != 0)
