--- src/pppoe.h.orig	Thu Mar 22 14:43:00 2001
+++ src/pppoe.h	Thu Mar 22 14:47:21 2001
@@ -72,7 +72,8 @@
 #ifdef USE_BPF
 extern int bpfSize;
 struct PPPoEPacketStruct;
-void sessionDiscoveryPacket(struct PPPoEPacketStruct *packet);
+struct PPPoEConnectionStruct;
+void sessionDiscoveryPacket(struct PPPoEConnectionStruct *conn, struct PPPoEPacketStruct *packet);
 #define BPF_BUFFER_IS_EMPTY (bpfSize <= 0)
 #define BPF_BUFFER_HAS_DATA (bpfSize > 0)
 #define ethhdr ether_header
