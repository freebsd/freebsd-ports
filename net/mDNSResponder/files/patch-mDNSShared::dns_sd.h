--- mDNSShared/dns_sd.h.old	Fri Mar 19 15:38:48 2004
+++ mDNSShared/dns_sd.h	Fri Mar 19 15:38:58 2004
@@ -46,7 +46,11 @@
 
 #include <sys/types.h>
 #include <sys/socket.h>
+#if defined(__FreeBSD__) && __FreeBSD_version >= 500000
 #include <stdint.h>
+#elif !defined(__FreeBSD__)
+#include <stdint.h>
+#endif
 #include <netinet/in.h>
 
 
