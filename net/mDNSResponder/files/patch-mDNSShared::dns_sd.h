--- mDNSShared/dns_sd.h.orig	Sat Dec 18 04:14:23 2004
+++ mDNSShared/dns_sd.h	Mon Feb 14 13:52:41 2005
@@ -39,6 +39,7 @@
 #define DNSSD_API
 #endif
 
+#include <osreldate.h>
 #if defined(__FreeBSD_version) && (__FreeBSD_version < 500000)
 /* stdint.h does not exist on FreeBSD 4.x; its types are defined in sys/types.h instead */
 #include <sys/types.h>
