--- src/pppoe.c.orig	Thu Mar 22 02:50:33 2001
+++ src/pppoe.c	Thu Mar 22 14:42:44 2001
@@ -109,7 +109,7 @@
 * packet before passing it here.
 ***********************************************************************/
 void
-sessionDiscoveryPacket(PPPoEPacket *packet)
+sessionDiscoveryPacket(PPPoEConnection *conn, PPPoEPacket *packet)
 {
     /* Sanity check */
     if (packet->code != CODE_PADT) {
@@ -117,7 +117,7 @@
     }
 
     /* It's a PADT, all right.  Is it for us? */
-    if (packet->session != Session) {
+    if (packet->session != conn->session) {
 	/* Nope, ignore it */
 	return;
     }
@@ -222,9 +222,9 @@
     /* check for buffered session data */
     while (BPF_BUFFER_HAS_DATA) {
 	if (conn->synchronous) {
-	    syncReadFromEth(conn->sessionSocket, optClampMSS);
+	    syncReadFromEth(conn, conn->sessionSocket, optClampMSS);
 	} else {
-	    asyncReadFromEth(conn->sessionSocket, optClampMSS);
+	    asyncReadFromEth(conn, conn->sessionSocket, optClampMSS);
 	}
     }
 #endif
@@ -642,7 +642,7 @@
     /* Make sure this is a session packet before processing further */
     type = etherType(&packet);
     if (type == Eth_PPPOE_Discovery) {
-	sessionDiscoveryPacket(&packet);
+	sessionDiscoveryPacket(conn,&packet);
     } else if (type != Eth_PPPOE_Session) {
 	return;
     }
@@ -767,7 +767,7 @@
     /* Make sure this is a session packet before processing further */
     type = etherType(&packet);
     if (type == Eth_PPPOE_Discovery) {
-	sessionDiscoveryPacket(&packet);
+	sessionDiscoveryPacket(conn,&packet);
     } else if (type != Eth_PPPOE_Session) {
 	return;
     }
