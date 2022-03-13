--- src/daemon/lldpd.h.orig    2022-03-09 14:30:41 UTC
+++ src/daemon/lldpd.h
@@ -33,8 +33,9 @@
 #include <string.h>
 #include <sys/queue.h>
 #include <sys/types.h>
-#include <netinet/if_ether.h>
+#include <sys/socket.h>
 #include <netinet/in.h>
+#include <netinet/if_ether.h>
 #include <sys/un.h>
 
 #include "lldp-tlv.h"
