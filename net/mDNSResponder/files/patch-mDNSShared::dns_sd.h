--- ./mDNSShared/dns_sd.h.orig	Tue Aug  8 17:27:30 2006
+++ ./mDNSShared/dns_sd.h	Tue Aug  8 17:27:52 2006
@@ -39,6 +39,7 @@
 #define DNSSD_API
 #endif
 
+#include <osreldate.h>
 #if defined(__FreeBSD_version) && (__FreeBSD_version < 500000)
 /* stdint.h does not exist on FreeBSD 4.x; its types are defined in sys/types.h instead */
 #include <sys/types.h>
