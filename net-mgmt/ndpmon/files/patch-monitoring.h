
$FreeBSD$

--- monitoring.h.orig
+++ monitoring.h
@@ -36,8 +36,9 @@
 
 #include <time.h>
 
+#include <sys/types.h>
 #include <netinet/in.h>
-#include <netinet/ether.h>
+#include <net/ethernet.h>
 #include <netinet/ip6.h>
 #include <netinet/icmp6.h>
 #include <string.h>
