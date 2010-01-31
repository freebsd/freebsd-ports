--- tcpip.cc.orig	Fri Dec  8 04:01:19 2006
+++ tcpip.cc	Wed Jan  3 17:15:05 2007
@@ -133,6 +133,8 @@
 #endif /* NETINET_IF_ETHER_H */
 #endif /* HAVE_NETINET_IF_ETHER_H */
 
+#include <sys/param.h>
+
 extern NmapOps o;
 
 #ifdef WIN32
