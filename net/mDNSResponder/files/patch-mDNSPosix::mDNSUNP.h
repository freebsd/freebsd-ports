--- mDNSPosix/mDNSUNP.h.old	Fri Mar 19 15:34:56 2004
+++ mDNSPosix/mDNSUNP.h	Fri Mar 19 15:38:28 2004
@@ -67,7 +67,11 @@
 #ifndef __mDNSUNP_h
 #define __mDNSUNP_h
 
+#if defined(__FreeBSD__) && __FreeBSD_version >= 500000
 #include <stdint.h>
+#elif !defined(__FreeBSD__)
+#include <stdint.h>
+#endif
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <net/if.h>
