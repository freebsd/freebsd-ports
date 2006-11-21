--- uproxy.c.orig	Thu Aug 10 11:05:10 2006
+++ uproxy.c	Fri Oct 20 13:17:01 2006
@@ -25,11 +25,11 @@
     #include <winsock.h>
 #else
     #include <sys/ioctl.h>
+    #include <sys/types.h>
     #include <sys/socket.h>
     #include <netinet/in.h>
     #include <arpa/inet.h>
     #include <sys/time.h>
-    #include <sys/types.h>
     #include <unistd.h>
     #include <stdlib.h>
 #endif
@@ -50,7 +50,7 @@

 SOCKET ProxySocket;
 struct sockaddr_in ProxySAddr, ClientSAddr, TargetSAddr;
-struct sockaddr AnySAddr={AF_INET, {INADDR_ANY}};
+struct sockaddr AnySAddr={AF_INET, INADDR_ANY};
 struct ClientList
 {
     SOCKET sock;
