--- a/src/xvdr/xvdrserver.c
+++ b/src/xvdr/xvdrserver.c
@@ -156,6 +156,7 @@ void cXVDRServer::NewClientConnected(int
   int val = 1;
   setsockopt(fd, SOL_SOCKET, SO_KEEPALIVE, &val, sizeof(val));
 
+#ifndef __FreeBSD__
   val = 30;
   setsockopt(fd, SOL_TCP, TCP_KEEPIDLE, &val, sizeof(val));
 
@@ -167,6 +168,10 @@ void cXVDRServer::NewClientConnected(int
 
   val = 1;
   setsockopt(fd, SOL_TCP, TCP_NODELAY, &val, sizeof(val));
+#else
+  val = 1;
+  setsockopt(fd, IPPROTO_TCP, TCP_NODELAY, &val, sizeof(val));
+#endif
 
   INFOLOG("Client with ID %d connected: %s", m_IdCnt, cxSocket::ip2txt(sin.sin_addr.s_addr, sin.sin_port, buf));
   cXVDRClient *connection = new cXVDRClient(fd, m_IdCnt, cxSocket::ip2txt(sin.sin_addr.s_addr, sin.sin_port, buf));
