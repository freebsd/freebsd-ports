--- src/rapihandshakeclient.cpp.orig	2008-04-15 11:38:15.000000000 +0200
+++ src/rapihandshakeclient.cpp	2008-04-15 11:38:23.000000000 +0200
@@ -17,6 +17,11 @@
 #include <udpsocket.h>
 #include <synce_log.h>
 
+#if defined(__FreeBSD__) && defined(__sparc64__)
+#include <sys/endian.h>
+#define bswap_16 bswap16
+#define bswap_32 bswap32
+#endif
 
 RapiHandshakeClient::RapiHandshakeClient( int fd, TCPServerSocket *tcpServerSocket )
         : RapiClient( fd, tcpServerSocket )
