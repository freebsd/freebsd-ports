--- protocols/arp/nd_arp.h.orig	Sat Oct 12 00:17:24 2002
+++ protocols/arp/nd_arp.h	Sat Oct 12 00:17:38 2002
@@ -26,6 +26,7 @@
 #ifndef __nd_arp_h
 #define __nd_arp_h
 
+#include <sys/socket.h>
 #include <net/ethernet.h>
 #include <net/if_arp.h>
 
