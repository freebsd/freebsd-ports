--- boreas/sniffer.c	2021-01-04 16:55:42.803387000 -0500
+++ boreas/sniffer.c	2021-01-04 16:57:10.155504000 -0500
@@ -25,6 +25,8 @@
 #include <arpa/inet.h>
 #include <errno.h>
 #include <glib.h>
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <net/if_arp.h>
 #include <netinet/ip.h>
 #include <stdlib.h>
