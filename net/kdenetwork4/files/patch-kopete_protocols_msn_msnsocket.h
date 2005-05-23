--- kopete/protocols/msn/msnsocket.h	Sun Nov 21 22:58:55 2004
+++ kopete/protocols/msn/msnsocket.h	Sun May 22 13:33:31 2005
@@ -124,12 +124,6 @@
 	 */
 	void socketClosed();
 
-	/**
-	 * The socket just sent a command from the queue. This signal is used in
-	 * the notify socket to reset the keepalive timer.
-	 */
-	void commandSent();
-
 protected:
 	/**
 	 * Convenience method: escape spaces with '%20' for use in the protocol.
