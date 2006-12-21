
$FreeBSD$

--- ndpmon.h.orig
+++ ndpmon.h
@@ -38,7 +38,7 @@
 
 #include <netinet/in.h>
 #include <netinet/if_ether.h> 
-#include <netinet/ether.h>
+#include <net/ethernet.h>
 #include <netinet/ip6.h>
 #include <netinet/icmp6.h>
 #include <net/ethernet.h>
