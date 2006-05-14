--- mDNSShared/dns_sd.h.orig	Tue Dec 20 22:24:58 2005
+++ mDNSShared/dns_sd.h	Fri Mar 10 14:41:32 2006
@@ -42,6 +42,7 @@
 #endif
 
 /* stdint.h does not exist on FreeBSD 4.x; its types are defined in sys/types.h instead */
+#include <osreldate.h>
 #if defined(__FreeBSD_version) && (__FreeBSD_version < 500000)
 #include <sys/types.h>
 
