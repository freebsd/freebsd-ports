--- pinger.h.orig	1999-07-23 14:08:26 UTC
+++ pinger.h
@@ -2,6 +2,7 @@
 #define __PINGER_H__
 
 
+#include <sys/types.h>
 #include <netinet/in.h>
 #include "list.h"
 #include "config.h"
@@ -47,9 +48,11 @@
 #define UDP_DPORT dest
 #endif
 
+#if ! (defined __FreeBSD__ || defined __DragonFly__)
 #if ! (defined(__GLIBC__) && (__GLIBC__ >= 2))
 #define inet_ntoa(x) inet_ntoa(*((struct in_addr *)&(x)))
 #endif
+#endif
 
 #define TIMEOUT_SIZE 55
 
