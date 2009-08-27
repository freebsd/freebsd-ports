--- src/protocols.h.orig	2006-07-16 16:37:31.000000000 +0400
+++ src/protocols.h	2009-08-27 18:30:35.000000000 +0400
@@ -26,6 +26,7 @@
 #define __PROTOCOLS_H__
 
 #include <pcap.h>
+#include <sys/socket.h>
 #include <net/if.h>
 
 #ifdef SOLARIS
