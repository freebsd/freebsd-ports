
$FreeBSD$

--- monitoring_rd.h.orig
+++ monitoring_rd.h
@@ -33,7 +33,9 @@
 #ifndef _MONITORING_RD_
 #define _MONITORING_RD_ 1
 
-#include <netinet/ether.h>
+#include <sys/types.h>
+#include <netinet/in.h>
+#include <net/ethernet.h>
 #include <netinet/ip6.h>
 #include <netinet/icmp6.h>
 
