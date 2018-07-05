--- apps/streaming/java/src/net/i2p/client/streaming/impl/I2PServerSocketFull.java.orig	2018-06-26 11:12:11 UTC
+++ apps/streaming/java/src/net/i2p/client/streaming/impl/I2PServerSocketFull.java
@@ -8,6 +8,7 @@ import net.i2p.client.streaming.AcceptingChannel;
 import net.i2p.client.streaming.I2PServerSocket;
 import net.i2p.client.streaming.I2PSocket;
 import net.i2p.client.streaming.I2PSocketManager;
+import net.i2p.client.streaming.RouterRestartException;
 
 /**
  * Bridge to allow accepting new connections
@@ -35,7 +36,7 @@ class I2PServerSocketFull implements I2PServerSocket {
      *         Not actually thrown through 0.9.16; thrown as of 0.9.17
      * @throws SocketTimeoutException if a timeout was previously set with setSoTimeout and the timeout has been reached.
      */
-    public I2PSocket accept() throws I2PException, ConnectException, SocketTimeoutException {
+    public I2PSocket accept() throws I2PException, RouterRestartException, ConnectException, SocketTimeoutException {
         return _socketManager.receiveSocket();
     }
 
