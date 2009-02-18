--- socklib.c.orig	2008-09-18 22:43:15.000000000 +0200
+++ socklib.c	2009-02-10 10:01:40.000000000 +0100
@@ -18,6 +18,7 @@
 #endif
 
 #ifdef HAVE_NET_IF_H
+# include <sys/socket.h>
 # include <net/if.h>
 #endif
 
@@ -66,6 +67,8 @@
 # define DEBUG 0
 #endif
 
+#undef SIOCGIFINDEX
+
 #ifdef LOSSTEST
 /**
  * Packet loss/swap testing...
@@ -353,7 +356,7 @@
 
 int setTtl(int sock, int ttl) {
     /* set the socket to broadcast */
-    return setsockopt(sock, SOL_IP, IP_MULTICAST_TTL, (char*)&ttl, sizeof(int));
+    return setsockopt(sock, IPPROTO_IP, IP_MULTICAST_TTL, (char*)&ttl, sizeof(int));
 }
 
 #ifdef HAVE_STRUCT_IP_MREQN_IMR_IFINDEX
@@ -422,7 +425,7 @@
 
 
 int setMcastDestination(int sock, net_if_t *net_if, struct sockaddr_in *addr) {
-#ifdef WINDOWS
+#if defined(WINDOWS) || defined(__FreeBSD__)
     int r;
     struct sockaddr_in interface_addr;
     struct in_addr if_addr;
@@ -720,7 +723,7 @@
 
 	net_if->name = strdup(chosen->ifr_name);
 
-#ifdef HAVE_STRUCT_IP_MREQN_IMR_IFINDEX
+#ifdef HAVE_STRUCT_IP_MREQN_IMR_IFINDEX__TODO
 	/* Index for multicast subscriptions */
 	if(ioctl(s,  SIOCGIFINDEX, chosen) < 0)
 	    udpc_fatal(-1, "Error getting index for %s: %s", net_if->name,
