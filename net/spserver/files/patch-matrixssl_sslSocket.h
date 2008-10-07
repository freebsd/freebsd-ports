--- matrixssl/sslSocket.h.orig	2008-10-06 11:22:38.000000000 +0800
+++ matrixssl/sslSocket.h	2008-10-06 11:22:48.000000000 +0800
@@ -48,7 +48,7 @@
 	#define		MSG_NOSIGNAL	0
 	#define		WOULD_BLOCK	WSAEWOULDBLOCK
 	#define		getSocketError()  WSAGetLastError()
-#elif linux
+#elif linux || FreeBSD
 	#include	<sys/socket.h>
 	#include	<netinet/in.h>
 	#include	<netinet/tcp.h>
