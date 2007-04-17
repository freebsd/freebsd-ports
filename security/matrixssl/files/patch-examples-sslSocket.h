--- ../examples/sslSocket.h.orig	Tue Apr 17 18:22:16 2007
+++ ../examples/sslSocket.h	Tue Apr 17 18:22:39 2007
@@ -49,6 +49,7 @@
 	#define		WOULD_BLOCK	WSAEWOULDBLOCK
 	#define		getSocketError()  WSAGetLastError()
 #elif LINUX
+	#include	<sys/types.h>
 	#include	<sys/socket.h>
 	#include	<netinet/in.h>
 	#include	<netinet/tcp.h>
