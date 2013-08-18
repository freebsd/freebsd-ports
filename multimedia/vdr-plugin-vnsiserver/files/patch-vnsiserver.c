--- a/vnsiserver.c
+++ b/vnsiserver.c
@@ -156,6 +156,7 @@ void cVNSIServer::NewClientConnected(int
   int val = 1;
   setsockopt(fd, SOL_SOCKET, SO_KEEPALIVE, &val, sizeof(val));
 
+#ifdef SOL_TCP
   val = 30;
   setsockopt(fd, SOL_TCP, TCP_KEEPIDLE, &val, sizeof(val));
 
@@ -167,6 +168,7 @@ void cVNSIServer::NewClientConnected(int
 
   val = 1;
   setsockopt(fd, SOL_TCP, TCP_NODELAY, &val, sizeof(val));
+#endif
 
   INFOLOG("Client with ID %d connected: %s", m_IdCnt, cxSocket::ip2txt(sin.sin_addr.s_addr, sin.sin_port, buf));
   cVNSIClient *connection = new cVNSIClient(fd, m_IdCnt, cxSocket::ip2txt(sin.sin_addr.s_addr, sin.sin_port, buf));
