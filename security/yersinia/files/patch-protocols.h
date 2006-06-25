--- src/protocols.h~	Sun Jun 18 17:23:33 2006
+++ src/protocols.h	Sun Jun 25 11:46:35 2006
@@ -26,6 +26,7 @@
 #define __PROTOCOLS_H__
 
 #include <pcap.h>
+#include <sys/socket.h>
 #include <net/if.h>
 
 #ifdef SOLARIS
