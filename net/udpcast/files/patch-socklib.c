--- socklib.c.orig	Sat Feb 21 13:58:37 2004
+++ socklib.c	Tue Jul 20 17:58:51 2004
@@ -16,6 +16,8 @@
 #include "log.h"
 #include "socklib.h"
 
+#undef SIOCGIFINDEX
+
 #ifdef LOSSTEST
 /**
  * Packet loss/swap testing...
@@ -289,7 +291,7 @@
 
 int setTtl(int sock, int ttl) {
     /* set the socket to broadcast */
-    return setsockopt(sock, SOL_IP, IP_MULTICAST_TTL, &ttl, sizeof(int));
+    return setsockopt(sock, IPPROTO_IP, IP_MULTICAST_TTL, &ttl, sizeof(int));
 }
 
 #ifdef SIOCGIFINDEX
@@ -334,7 +336,7 @@
     int r;
     
     fillMreq(sock, ifname, addr, &mreq);
-    r = setsockopt(sock, SOL_IP, code, &mreq, sizeof(mreq));
+    r = setsockopt(sock, IPPROTO_IP, code, &mreq, sizeof(mreq));
     if(r < 0) {
 	perror(message);
 	exit(1);
@@ -366,7 +368,7 @@
 
 
 int setMcastDestination(int sock, char *ifname, struct sockaddr *addr) {
-#ifdef __CYGWIN__
+#if defined(__CYGWIN__) || defined(__FreeBSD__)
     int r;
     struct sockaddr interface_addr;
     struct in_addr if_addr;
