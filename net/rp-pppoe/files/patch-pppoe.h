--- ./pppoe.h.orig	2012-08-17 20:31:25.000000000 +0200
+++ ./pppoe.h	2012-09-23 17:27:26.000000000 +0200
@@ -72,10 +72,14 @@
 #include <net/if_ppp.h>
 #endif
 
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#include <net/ethernet.h>
+#endif
+
 #ifdef USE_BPF
 extern int bpfSize;
 struct PPPoEPacketStruct;
-void sessionDiscoveryPacket(struct PPPoEPacketStruct *packet);
 #define BPF_BUFFER_IS_EMPTY (bpfSize <= 0)
 #define BPF_BUFFER_HAS_DATA (bpfSize > 0)
 #define ethhdr ether_header
