--- tcpclient.cc.orig	2016-07-02 18:06:10 UTC
+++ tcpclient.cc
@@ -75,7 +75,7 @@ int TcpClient::Connect(const char *in_remotehost, shor
     local_sock.sin_addr.s_addr = htonl(INADDR_ANY);
     local_sock.sin_port = htons(0);
 
-    if (bind(cli_fd, (struct sockaddr *) &local_sock, sizeof(local_sock)) < 0) {
+    if (::bind(cli_fd, (struct sockaddr *) &local_sock, sizeof(local_sock)) < 0) {
         snprintf(errstr, 1024, "TCP client bind() failed: %s", strerror(errno));
         globalreg->messagebus->InjectMessage(errstr, MSGFLAG_ERROR);
 		close(cli_fd);
@@ -170,7 +170,7 @@ int TcpClient::ConnectSync(const char *in_remotehost, 
     local_sock.sin_addr.s_addr = htonl(INADDR_ANY);
     local_sock.sin_port = htons(0);
 
-    if (bind(cli_fd, (struct sockaddr *) &local_sock, sizeof(local_sock)) < 0) {
+    if (::bind(cli_fd, (struct sockaddr *) &local_sock, sizeof(local_sock)) < 0) {
         snprintf(errstr, 1024, "TCP client bind() failed: %s", strerror(errno));
         globalreg->messagebus->InjectMessage(errstr, MSGFLAG_ERROR);
 		close(cli_fd);
