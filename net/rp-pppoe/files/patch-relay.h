--- ./relay.h.orig	2012-08-17 20:31:25.000000000 +0200
+++ ./relay.h	2012-09-23 17:27:26.000000000 +0200
@@ -51,8 +51,13 @@
 
 /* Function prototypes */
 
+#if defined(__FreeBSD__)
+void relayGotSessionPacket(PPPoEInterface const *iface, PPPoEPacket *packet, int size);
+void relayGotDiscoveryPacket(PPPoEInterface const *iface, PPPoEPacket *packet, int size);
+#else
 void relayGotSessionPacket(PPPoEInterface const *i);
 void relayGotDiscoveryPacket(PPPoEInterface const *i);
+#endif
 PPPoEInterface *findInterface(int sock);
 unsigned int hash(unsigned char const *mac, UINT16_t sesNum);
 SessionHash *findSession(unsigned char const *mac, UINT16_t sesNum);
