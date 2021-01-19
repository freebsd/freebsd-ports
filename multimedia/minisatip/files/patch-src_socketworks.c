--- src/socketworks.c.orig	2020-08-16 05:56:14 UTC
+++ src/socketworks.c
@@ -1023,7 +1023,7 @@ void set_sockets_rtime(int i, int r)
 	if (ss)
 		ss->rtime = r;
 }
-#ifndef __APPLE__
+#ifdef __linux__
 
 int get_mac_address(char *mac)
 {
@@ -1658,7 +1658,9 @@ void set_socket_dscp(int id, int dscp, int prio)
 	setsockopt(id, IPPROTO_IP, IP_TOS, &d, sizeof(d));
 
 	d = prio;
+#if defined(SO_PRIORITY)
 	setsockopt(id, SOL_SOCKET, SO_PRIORITY, &d, sizeof(d));
+#endif
 }
 
 void sockets_set_opaque(int id, void *opaque, void *opaque2, void *opaque3)
