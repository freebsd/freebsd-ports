--- tcpip.cc.orig	Thu Jun 17 13:36:02 2004
+++ tcpip.cc	Thu Jun 17 13:38:54 2004
@@ -1769,7 +1769,7 @@
 #if TCPIP_DEBUGGING
     printf("ifnet list length = %d\n",ifc.ifc_len);
     printf("sa_len = %d\n",len);
-    hdump(buf, ifc.ifc_len);
+    hdump((unsigned char *)buf, ifc.ifc_len);
     printf("ifr = %X\n",(unsigned int)(*(char **)&ifr));
     printf("Size of struct ifreq: %d\n", sizeof(struct ifreq));
 #endif
@@ -2214,7 +2214,7 @@
     error("sendto in %s: sendto(%d, packet, %d, 0, %s, %d) => %s",
 	  functionname, sd, len, inet_ntoa(sin->sin_addr), tolen,
 	  strerror(socket_errno()));
-    if (retries > 2 || socket_errno() == EPERM) 
+    if (retries > 2 || socket_errno() == EPERM || socket_errno() == EACCES || socket_errno() == EADDRNOTAVAIL) 
       return -1;
     sleeptime = 15 * (1 << (2 * retries));
     error("Sleeping %d seconds then retrying", sleeptime);
