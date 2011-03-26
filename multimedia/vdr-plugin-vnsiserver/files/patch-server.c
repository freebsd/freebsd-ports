--- a/server.c
+++ b/server.c
@@ -151,6 +151,7 @@ void cServer::NewClientConnected(int fd)
   int val = 1;
   setsockopt(fd, SOL_SOCKET, SO_KEEPALIVE, &val, sizeof(val));
 
+#ifdef SOL_TCP
   val = 30;
   setsockopt(fd, SOL_TCP, TCP_KEEPIDLE, &val, sizeof(val));
 
@@ -162,6 +163,7 @@ void cServer::NewClientConnected(int fd)
 
   val = 1;
   setsockopt(fd, SOL_TCP, TCP_NODELAY, &val, sizeof(val));
+#endif
 
   isyslog("VNSI: Client with ID %d connected: %s", m_IdCnt, cxSocket::ip2txt(sin.sin_addr.s_addr, sin.sin_port, buf));
   cConnection *connection = new cConnection(this, fd, m_IdCnt, cxSocket::ip2txt(sin.sin_addr.s_addr, sin.sin_port, buf));
