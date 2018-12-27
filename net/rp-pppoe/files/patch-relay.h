--- relay.h.orig	2018-11-25 22:25:28 UTC
+++ relay.h
@@ -51,8 +51,13 @@ typedef struct SessionHashStruct {
 
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
