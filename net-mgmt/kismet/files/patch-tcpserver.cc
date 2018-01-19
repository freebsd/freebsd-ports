--- tcpserver.cc.orig	2016-07-02 18:06:10 UTC
+++ tcpserver.cc
@@ -84,7 +84,7 @@ int TcpServer::EnableServer() {
     }
 
     // Bind the socket
-    if (bind(serv_fd, (struct sockaddr *) &serv_sock, sizeof(serv_sock)) < 0) {
+    if (::bind(serv_fd, (struct sockaddr *) &serv_sock, sizeof(serv_sock)) < 0) {
         snprintf(errstr, STATUS_MAX, "TCP server bind() failed: %s",
                  strerror(errno));
         globalreg->messagebus->InjectMessage(errstr, MSGFLAG_ERROR);
