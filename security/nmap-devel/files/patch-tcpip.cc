--- tcpip.cc.orig	2020-10-02 16:12:22 UTC
+++ tcpip.cc
@@ -83,6 +83,8 @@
 #endif /* NETINET_IF_ETHER_H */
 #endif /* HAVE_NETINET_IF_ETHER_H */
 
+#include <sys/param.h>
+
 extern NmapOps o;
 
 static PacketCounter PktCt;
