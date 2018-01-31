--- tcpip.cc.orig	2017-06-07 12:32:38 UTC
+++ tcpip.cc
@@ -151,6 +151,8 @@
 #endif /* NETINET_IF_ETHER_H */
 #endif /* HAVE_NETINET_IF_ETHER_H */
 
+#include <sys/param.h>
+
 extern NmapOps o;
 
 static PacketCounter PktCt;
