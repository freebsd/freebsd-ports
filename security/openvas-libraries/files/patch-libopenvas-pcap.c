
$FreeBSD$

--- libopenvas/pcap.c.orig
+++ libopenvas/pcap.c
@@ -16,9 +16,7 @@
  * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
  */
 
-#include <resolv.h>
 #include <pcap.h>
-#include <net/if.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <sys/ioctl.h>
@@ -29,6 +27,10 @@
 #include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
+#include <sys/param.h>
+#include <net/if.h>
 
 #include "bpf_share.h"
 #include "pcap_openvas.h"
