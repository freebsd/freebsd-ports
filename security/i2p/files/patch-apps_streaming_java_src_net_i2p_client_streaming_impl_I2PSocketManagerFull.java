--- apps/streaming/java/src/net/i2p/client/streaming/impl/I2PSocketManagerFull.java.orig	2018-06-26 11:12:11 UTC
+++ apps/streaming/java/src/net/i2p/client/streaming/impl/I2PSocketManagerFull.java
@@ -28,6 +28,7 @@ import net.i2p.client.streaming.I2PServerSocket;
 import net.i2p.client.streaming.I2PSocket;
 import net.i2p.client.streaming.I2PSocketManager;
 import net.i2p.client.streaming.I2PSocketOptions;
+import net.i2p.client.streaming.RouterRestartException;
 import net.i2p.crypto.SigAlgo;
 import net.i2p.crypto.SigType;
 import net.i2p.data.Certificate;
@@ -354,7 +355,7 @@ public class I2PSocketManagerFull implements I2PSocket
      * @throws ConnectException (since 0.9.17; I2PServerSocket interface always declared it)
      * @throws SocketTimeoutException if a timeout was previously set with setSoTimeout and the timeout has been reached.
      */
-    public I2PSocket receiveSocket() throws I2PException, ConnectException, SocketTimeoutException {
+    public I2PSocket receiveSocket() throws I2PException, RouterRestartException, ConnectException, SocketTimeoutException {
         verifySession();
         Connection con = _connectionManager.getConnectionHandler().accept(_connectionManager.getSoTimeout());
         I2PSocketFull sock = new I2PSocketFull(con, _context);
