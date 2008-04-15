--- src/rapiproxyconnection.cpp.orig	2008-04-15 11:39:47.000000000 +0200
+++ src/rapiproxyconnection.cpp	2008-04-15 11:42:37.000000000 +0200
@@ -19,6 +19,12 @@
 
 #include <iostream>
 
+#if defined(__FreeBSD__) && defined(__sparc64__)
+#include <sys/endian.h>
+#define bswap_16 bswap16
+#define bswap_32 bswap32
+#endif
+
 RapiProxyConnection::RapiProxyConnection(RapiConnection *rapiConnection, RapiProxy *rapiProxy,
                                          RapiProvisioningClient *rapiProvisioningClient)
     : rapiConnection(rapiConnection),
