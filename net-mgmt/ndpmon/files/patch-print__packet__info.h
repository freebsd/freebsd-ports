
$FreeBSD$

--- print_packet_info.h.orig
+++ print_packet_info.h
@@ -37,7 +37,9 @@
 
 #include <stdio.h>
 #include <stdlib.h>
-#include <netinet/ether.h>
+#include <sys/types.h>
+#include <netinet/in.h>
+#include <net/ethernet.h>
 #include <netinet/ip6.h>
 #include <netinet/icmp6.h>
 
