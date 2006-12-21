
$FreeBSD$

--- monitoring_ns.h.orig
+++ monitoring_ns.h
@@ -33,7 +33,9 @@
 #ifndef _MONITORING_NS_
 #define _MONITORING_NS_ 1
 
-#include <netinet/ether.h>
+#include <sys/types.h>
+#include <netinet/in.h>
+#include <net/ethernet.h>
 #include <netinet/ip6.h>
 #include <netinet/icmp6.h>
 #include <netinet/in.h>
