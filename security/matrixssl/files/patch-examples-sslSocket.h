--- ../examples/sslSocket.h.orig	Fri Mar 17 16:32:41 2006
+++ ../examples/sslSocket.h	Fri Mar 17 16:32:59 2006
@@ -50,6 +50,7 @@
 	#define		getSocketError()  WSAGetLastError()
 #elif LINUX
 	#include	<sys/socket.h>
+	#include	<sys/types.h>
 	#include	<netinet/in.h>
 	#include	<netinet/tcp.h>
 	#include	<arpa/inet.h>
