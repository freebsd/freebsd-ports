--- src/xxxprotocol.h.orig	2008-01-04 18:25:54.000000000 +0200
+++ src/xxxprotocol.h		2008-04-21 01:20:02.000000000 +0300
@@ -4,7 +4,7 @@
 #include "global.h"
 #include "tcpsocket.h"
 #include "crypto.h"
-
+#include <sys/param.h>
 #ifdef WIN32
 #include <winsock.h>
 #endif
@@ -31,7 +31,7 @@
     uint port;
     int recvsd;		//UDP socket
     
-#if defined( FREEBSD )
+#if defined( BSD )
     struct sockaddr_dl *search(u_long addr);
 #endif
     
