--- net.c.orig	Thu Jan 13 08:13:53 2005
+++ net.c	Wed Nov 16 19:43:05 2005
@@ -277,7 +277,7 @@
       exit( EXIT_FAILURE);
     }
     echotype = ICMP6_ECHO_REQUEST;
-    salen = sizeof (struct sockaddr_storage);
+    salen = sizeof (struct sockaddr_in6);
     break;
 #endif
   }
@@ -305,7 +305,6 @@
     rv = sendto(sendsock, packet, abs(packetsize), 0, 
 		remotesockaddr, salen);
     if (rv >= 0) {
-      fprintf (stderr, "You've got a broken (FreeBSD?) system\n");
       BSDfix = 1;
     }
   }
@@ -346,7 +345,7 @@
     addrcpy( (void *) &(host[index].addrs[0]), addr, af );
   } else {
     for( i=0; i<MAXPATH; ) {
-      if( addrcmp( (void *) &(host[index].addrs[i]), (void *) &addr,
+      if( addrcmp( (void *) &(host[index].addrs[i]), addr,
                    af ) == 0 ||
           addrcmp( (void *) &(host[index].addrs[i]),
 		   (void *) &unspec_addr, af ) == 0 ) break;
