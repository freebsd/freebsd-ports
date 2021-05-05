--- src/socketworks.c.orig	2021-05-05 05:43:10 UTC
+++ src/socketworks.c
@@ -968,7 +968,7 @@ void set_sockets_rtime(int i, int r) {
     if (ss)
         ss->rtime = r;
 }
-#ifndef __APPLE__
+#ifdef __linux__
 
 int get_mac_address(char *mac) {
     struct ifreq ifr;
@@ -1562,8 +1562,12 @@ void set_socket_dscp(int id, int dscp, int prio) {
         LOG("%s: setsockopt IP_TOS failed", __FUNCTION__);
 
     d = prio;
+#if defined(SO_PRIORITY)
     if (setsockopt(id, SOL_SOCKET, SO_PRIORITY, &d, sizeof(d)))
         LOG("%s: setsockopt SO_PRIORITY failed", __FUNCTION__);
+#else
+    LOG("%s: setsockopt SO_PRIORITY not implemented", __FUNCTION__);
+#endif
 }
 
 void sockets_set_opaque(int id, void *opaque, void *opaque2, void *opaque3) {
