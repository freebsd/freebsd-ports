--- ../examples/sslSocket.h.orig	2010-02-01 00:06:47.000000000 +0100
+++ ../examples/sslSocket.h	2010-02-01 00:06:59.000000000 +0100
@@ -50,6 +50,7 @@
 	#define		getSocketError()  WSAGetLastError()
 #elif LINUX
 	#include	<sys/socket.h>
+	#include	<sys/types.h>
 	#include	<netinet/in.h>
 	#include	<netinet/tcp.h>
 	#include	<arpa/inet.h>
