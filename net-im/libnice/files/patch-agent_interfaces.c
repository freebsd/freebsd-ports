--- agent/interfaces.c.orig	2009-03-08 13:12:26.000000000 -0400
+++ agent/interfaces.c	2009-03-08 13:12:53.000000000 -0400
@@ -43,6 +43,7 @@
  #include <ifaddrs.h>
 #endif
 
+#include <netinet/in.h>
 #include <net/if.h>
 #include <net/if_arp.h>
 #include <arpa/inet.h>
