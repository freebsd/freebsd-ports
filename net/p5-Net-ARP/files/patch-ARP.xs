--- ARP.xs.orig	2013-06-24 05:15:16 UTC
+++ ARP.xs
@@ -27,7 +27,6 @@ See the GNU General Public License for m
 #include <string.h>          
 #include <errno.h>           
 #include <net/ethernet.h>    
-#include <netinet/ether.h>
 #include <net/if.h>
 #include <arpa/inet.h>       
 #include "arp.h"
