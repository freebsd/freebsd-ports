--- csocket.h.bak	Wed Aug 20 17:08:31 2003
+++ csocket.h	Wed Aug 20 17:09:01 2003
@@ -94,7 +94,7 @@
     int m_fdSocketNormal;                 // named stream socket descriptor - use for client/server exchange
     int m_fdSocketServer;                 // server socket - used by server to listen for connections
     int m_iLocalAddrLen;                  // local socket address length
-    int m_iRemoteAddrLen;                 // local socket address length
+    socklen_t m_iRemoteAddrLen;           // local socket address length
     struct sockaddr_un m_saunLocal;       // local socket address
     struct sockaddr_un m_saunRemote;      // remote socket address
     char m_szSocketPath[MAX_PATHNAME];    // named stream socket path

