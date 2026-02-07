--- src/misc.c.orig	2024-03-24 19:35:50 UTC
+++ src/misc.c
@@ -27,6 +27,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <ctype.h>
+#include <pcap/pcap.h>
 #include <netinet/if_ether.h>
 
 #include "ifaces.h"
