--- unixdomainserver.cc.orig	2016-07-02 18:06:10 UTC
+++ unixdomainserver.cc
@@ -64,7 +64,7 @@ int UnixDomainServer::EnableServer() {
     }
 
     // Bind the socket
-    if (bind(serv_fd, (struct sockaddr *) &serv_sock, sizeof(serv_sock)) < 0) {
+    if (::bind(serv_fd, (struct sockaddr *) &serv_sock, sizeof(serv_sock)) < 0) {
         _MSG("Unix domain server bind() failed: " + string(strerror(errno)),
              MSGFLAG_ERROR);
         return -1;
