--- src/tcpsocket.cpp.orig	Fri Jul 11 15:00:44 2003
+++ src/tcpsocket.cpp	Fri Jul 11 15:00:56 2003
@@ -212,7 +212,7 @@
 }
 
 bool TCPSocket::Accept() {
-   size_t sin_size = sizeof(struct sockaddr_in);
+   socklen_t sin_size = sizeof(struct sockaddr_in);
    //sockaddr_in RemoteAddress;
    if((newfd = accept(sockfd, (struct sockaddr *)&RemoteAddress, &sin_size)) == -1) {
       perror("accept");
