--- protocols/arp/nd_arp.h.orig	Wed Nov 20 20:57:00 2002
+++ protocols/arp/nd_arp.h	Wed Nov 20 20:57:26 2002
@@ -26,6 +26,8 @@
 #ifndef __nd_arp_h
 #define __nd_arp_h
 
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <net/ethernet.h>
 #include <net/if_arp.h>
 
