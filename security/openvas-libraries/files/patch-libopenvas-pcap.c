--- libopenvas/pcap.c.orig	2008-03-21 06:25:01.000000000 +0900
+++ libopenvas/pcap.c	2008-04-26 23:47:15.000000000 +0900
@@ -16,9 +16,7 @@
  * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
  */
 
-#include <resolv.h>
 #include <pcap.h>
-#include <net/if.h>
 #include <arpa/inet.h>
 #include <sys/ioctl.h>
 #include <netdb.h>
@@ -28,6 +26,10 @@
 #include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
+#include <sys/param.h>
+#include <net/if.h>
 
 #include "bpf_share.h"
 #include "pcap_openvas.h"
