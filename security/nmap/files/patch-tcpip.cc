--- tcpip.cc.orig	2015-06-30 18:34:28 UTC
+++ tcpip.cc
@@ -144,6 +144,8 @@
 #endif /* NETINET_IF_ETHER_H */
 #endif /* HAVE_NETINET_IF_ETHER_H */
 
+#include <sys/param.h>
+
 extern NmapOps o;
 
 #ifdef WIN32
