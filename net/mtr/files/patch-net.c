--- net.c.orig	Wed Aug 25 09:21:27 2004
+++ net.c	Tue Oct 26 12:46:58 2004
@@ -249,7 +249,6 @@
     rv = sendto(sendsock, packet, abs(packetsize), 0, 
 		(struct sockaddr *)&remoteaddress, sizeof(remoteaddress));
     if (rv >= 0) {
-      fprintf (stderr, "You've got a broken (FreeBSD?) system\n");
       BSDfix = 1;
     }
   }
