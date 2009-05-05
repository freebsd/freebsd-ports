--- ARP.xs.orig	2009-05-04 16:08:52.000000000 -0700
+++ ARP.xs	2009-05-04 16:08:58.000000000 -0700
@@ -27,7 +27,6 @@
 #include <string.h>          
 #include <errno.h>           
 #include <net/ethernet.h>    
-#include <netinet/ether.h>
 #include <net/if.h>
 #include <arpa/inet.h>       
 #include "arp.h"
