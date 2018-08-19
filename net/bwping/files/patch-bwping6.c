--- bwping6.c.orig	2018-08-04 00:31:13 UTC
+++ bwping6.c
@@ -12,9 +12,7 @@
 #include <netinet/in_systm.h>
 #include <netinet/ip.h>
 #include <netinet/ip6.h>
-#ifdef HAVE_NETINET_ICMP6_H
 #include <netinet/icmp6.h>
-#endif
 
 #include <netdb.h>
 
