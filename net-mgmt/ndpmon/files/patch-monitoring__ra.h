
$FreeBSD$

--- monitoring_ra.h.orig
+++ monitoring_ra.h
@@ -33,7 +33,9 @@
 #ifndef _MONITORING_RA_
 #define _MONITORING_RA_ 1
 
-#include <netinet/ether.h>
+#include <sys/types.h>
+#include <net/ethernet.h>
+#include <netinet/in.h>
 #include <netinet/ip6.h>
 #include <netinet/icmp6.h>
 
