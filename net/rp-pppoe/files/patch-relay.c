--- relay.c.orig	2018-11-25 22:25:28 UTC
+++ relay.c
@@ -754,6 +754,11 @@ void
 relayLoop()
 {
     fd_set readable, readableCopy;
+#if defined(__FreeBSD__)
+    PPPoEPacket packet;
+    int size;
+    int type;
+#endif
     int maxFD;
     int i, r;
     int sock;
@@ -783,6 +788,27 @@ relayLoop()
 	    continue;
 	}
 
+#if defined(__FreeBSD__)
+        for (i=0; i<NumInterfaces; i++) {
+            /* Because FreeBSD use one interface for both Discovery and
+            Session types we use first socket for packet receiving [SeaD] */
+            if (!FD_ISSET(Interfaces[i].discoverySock, &readableCopy))
+                continue;
+            if (receivePacket(Interfaces[i].discoverySock, &packet, &size) < 0)
+                continue;
+
+            /* Ignore unknown code/version */
+            if (packet.ver != 1 || packet.type != 1)
+                continue;
+
+            type = etherType(&packet);
+            if (type == Eth_PPPOE_Discovery) {
+                relayGotDiscoveryPacket(&Interfaces[i], &packet, size);
+            } else if (type == Eth_PPPOE_Session) {
+                relayGotSessionPacket(&Interfaces[i], &packet, size);
+            }
+        }
+#else
 	/* Handle session packets first */
 	for (i=0; i<NumInterfaces; i++) {
 	    if (FD_ISSET(Interfaces[i].sessionSock, &readableCopy)) {
@@ -797,6 +823,7 @@ relayLoop()
 	    }
 	}
 
+#endif
 	/* Handle the session-cleaning process */
 	if (FD_ISSET(CleanPipe[0], &readableCopy)) {
 	    char dummy;
@@ -816,7 +843,47 @@ relayLoop()
 *%DESCRIPTION:
 * Receives and processes a discovery packet.
 ***********************************************************************/
+#if defined(__FreeBSD__)
 void
+relayGotDiscoveryPacket(PPPoEInterface const *iface,
+                        PPPoEPacket *packet,
+                        int size)
+{
+
+    if (ntohs(packet->length) + HDR_SIZE > size) {
+	syslog(LOG_ERR, "Bogus PPPoE length field (%u)",
+	       (unsigned int) ntohs(packet->length));
+	return;
+    }
+
+    /* Drop Ethernet frame padding */
+    if (size > ntohs(packet->length) + HDR_SIZE) {
+	size = ntohs(packet->length) + HDR_SIZE;
+    }
+
+    switch(packet->code) {
+    case CODE_PADT:
+	relayHandlePADT(iface, packet, size);
+	break;
+    case CODE_PADI:
+	relayHandlePADI(iface, packet, size);
+	break;
+    case CODE_PADO:
+	relayHandlePADO(iface, packet, size);
+	break;
+    case CODE_PADR:
+	relayHandlePADR(iface, packet, size);
+	break;
+    case CODE_PADS:
+	relayHandlePADS(iface, packet, size);
+	break;
+    default:
+	syslog(LOG_ERR, "Discovery packet on %s with unknown code %d",
+	       iface->name, (int) packet->code);
+    }
+}
+#else
+void
 relayGotDiscoveryPacket(PPPoEInterface const *iface)
 {
     PPPoEPacket packet;
@@ -863,6 +930,7 @@ relayGotDiscoveryPacket(PPPoEInterface const *iface)
 	       iface->name, (int) packet.code);
     }
 }
+#endif
 
 /**********************************************************************
 *%FUNCTION: relayGotSessionPacket
@@ -873,7 +941,66 @@ relayGotDiscoveryPacket(PPPoEInterface const *iface)
 *%DESCRIPTION:
 * Receives and processes a session packet.
 ***********************************************************************/
+#if defined(__FreeBSD__)
 void
+relayGotSessionPacket(PPPoEInterface const *iface,
+                        PPPoEPacket *packet,
+                        int size)
+{
+    SessionHash *sh;
+    PPPoESession *ses;
+
+    /* Must be a session packet */
+    if (packet->code != CODE_SESS) {
+	syslog(LOG_ERR, "Session packet with code %d", (int) packet->code);
+	return;
+    }
+
+    /* Ignore session packets whose destination address isn't ours */
+    if (memcmp(packet->ethHdr.h_dest, iface->mac, ETH_ALEN)) {
+	return;
+    }
+
+    /* Validate length */
+    if (ntohs(packet->length) + HDR_SIZE > size) {
+	syslog(LOG_ERR, "Bogus PPPoE length field (%u)",
+	       (unsigned int) ntohs(packet->length));
+	return;
+    }
+
+    /* Drop Ethernet frame padding */
+    if (size > ntohs(packet->length) + HDR_SIZE) {
+	size = ntohs(packet->length) + HDR_SIZE;
+    }
+
+    /* We're in business!  Find the hash */
+    sh = findSession(packet->ethHdr.h_source, packet->session);
+    if (!sh) {
+	/* Don't log this.  Someone could be running the client and the
+	   relay on the same box. */
+	return;
+    }
+
+    /* Relay it */
+    ses = sh->ses;
+    ses->epoch = Epoch;
+    sh = sh->peer;
+    packet->session = sh->sesNum;
+    memcpy(packet->ethHdr.h_source, sh->interface->mac, ETH_ALEN);
+    memcpy(packet->ethHdr.h_dest, sh->peerMac, ETH_ALEN);
+#if 0
+    fprintf(stderr, "Relaying %02x:%02x:%02x:%02x:%02x:%02x(%s:%d) to %02x:%02x:%02x:%02x:%02x:%02x(%s:%d)\n",
+	    sh->peer->peerMac[0], sh->peer->peerMac[1], sh->peer->peerMac[2],
+	    sh->peer->peerMac[3], sh->peer->peerMac[4], sh->peer->peerMac[5],
+	    sh->peer->interface->name, ntohs(sh->peer->sesNum),
+	    sh->peerMac[0], sh->peerMac[1], sh->peerMac[2],
+	    sh->peerMac[3], sh->peerMac[4], sh->peerMac[5],
+	    sh->interface->name, ntohs(sh->sesNum));
+#endif
+    sendPacket(NULL, sh->interface->sessionSock, packet, size);
+}
+#else
+void
 relayGotSessionPacket(PPPoEInterface const *iface)
 {
     PPPoEPacket packet;
@@ -939,6 +1066,7 @@ relayGotSessionPacket(PPPoEInterface const *iface)
 #endif
     sendPacket(NULL, sh->interface->sessionSock, &packet, size);
 }
+#endif
 
 /**********************************************************************
 *%FUNCTION: relayHandlePADT
