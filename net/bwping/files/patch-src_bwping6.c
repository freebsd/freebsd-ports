--- src/bwping6.c.orig	2019-04-08 01:59:16 UTC
+++ src/bwping6.c
@@ -25,9 +25,7 @@
 #include <netinet/in.h>
 #include <netinet/in_systm.h>
 #include <netinet/ip6.h>
-#ifdef HAVE_NETINET_ICMP6_H
 #include <netinet/icmp6.h>
-#endif
 
 #ifdef __CYGWIN__
 #include <netinet/ip.h>
