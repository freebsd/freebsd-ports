--- tcpip.cc.orig	2015-06-16 13:59:33 UTC
+++ tcpip.cc
@@ -154,6 +154,8 @@
 #endif /* NETINET_IF_ETHER_H */
 #endif /* HAVE_NETINET_IF_ETHER_H */
 
+#include <sys/param.h>
+
 extern NmapOps o;
 
 #ifdef WIN32
