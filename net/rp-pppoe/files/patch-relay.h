--- relay.h.orig	2020-05-27 00:29:37 UTC
+++ relay.h
@@ -52,8 +52,13 @@ typedef struct SessionHashStruct {
 
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
