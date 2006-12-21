
$FreeBSD$

--- monitoring_na.h.orig
+++ monitoring_na.h
@@ -34,7 +34,9 @@
 #ifndef _MONITORING_NA_
 #define _MONITORING_NA_ 1
 
-#include <netinet/ether.h>
+#include <sys/types.h>
+#include <netinet/in.h>
+#include <net/ethernet.h>
 #include <netinet/ip6.h>
 #include <netinet/icmp6.h>
 
