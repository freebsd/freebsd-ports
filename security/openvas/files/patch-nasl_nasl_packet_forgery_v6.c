--- nasl/nasl_packet_forgery_v6.c	2020-08-11 07:00:25.000000000 -0500
+++ nasl/nasl_packet_forgery_v6.c	2021-01-04 17:39:47.104902000 -0500
@@ -36,6 +36,8 @@
  * 09/02/2010 Preeti Subramanian <spreeti@secpod.com>
  */
 
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <arpa/inet.h> /* for inet_aton */
 #include <ctype.h>     /* for isprint */
 #include <pcap.h>      /* for PCAP_ERRBUF_SIZE */
@@ -44,9 +46,7 @@
 #include <sys/param.h>
 #include <sys/time.h> /* for gettimeofday */
 #include <unistd.h>   /* for close */
-#ifdef __FreeBSD__
 #include <netinet/in.h>
-#endif
 
 #include "../misc/bpf_share.h"    /* for bpf_open_live */
 #include "../misc/pcap_openvas.h" /* for routethrough */
