--- util/transport/UdpStack.cxx.orig	Sun Oct 10 21:24:12 2004
+++ util/transport/UdpStack.cxx	Sun Oct 10 21:26:32 2004
@@ -97,7 +97,10 @@
 #endif
 
 #ifdef __FreeBSD__
+#include <sys/param.h>
+#if __FreeBSD_version < 503001
 #include <isc/eventlib.h>
+#endif
 #endif
 
 #ifdef __APPLE__
