--- pppoe.h.orig	2018-11-25 22:25:28 UTC
+++ pppoe.h
@@ -65,10 +65,14 @@ extern int IsSetID;
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
