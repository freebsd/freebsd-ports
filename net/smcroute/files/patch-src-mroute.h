--- src/mroute.h.orig	2024-05-09 17:03:52 UTC
+++ src/mroute.h
@@ -34,7 +34,9 @@
 #endif
 
 #ifdef HAVE_NETINET_IP_MROUTE_H
+#ifndef __FreeBSD__
 #define _KERNEL
+#endif
 #include <netinet/ip_mroute.h>
 #undef _KERNEL
 #else
