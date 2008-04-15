--- src/rapiconnection.cpp.orig	2008-04-15 11:39:02.000000000 +0200
+++ src/rapiconnection.cpp	2008-04-15 11:39:14.000000000 +0200
@@ -22,6 +22,12 @@
 #include "synce_log.h"
 #include <multiplexer.h>
 
+#if defined(__FreeBSD__) && defined(__sparc64__)
+#include <sys/endian.h>
+#define bswap_16 bswap16
+#define bswap_32 bswap32
+#endif
+
 using namespace std;
 
 RapiConnection::RapiConnection(RapiProxyFactory *proxyFactory, string path, RapiServer *rapiServer, string deviceIpAddress) : LocalServerSocket(proxyFactory, path), rapiHandshakeClient(NULL), deviceIpAddress(deviceIpAddress), rapiServer(rapiServer)
