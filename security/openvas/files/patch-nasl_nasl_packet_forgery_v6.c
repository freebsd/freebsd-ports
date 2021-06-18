--- nasl/nasl_packet_forgery_v6.c	2021-04-15 09:39:00.000000000 -0500
+++ nasl/nasl_packet_forgery_v6.c	2021-06-14 20:22:58.395635000 -0500
@@ -36,6 +36,8 @@
  * 09/02/2010 Preeti Subramanian <spreeti@secpod.com>
  */
 
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <arpa/inet.h> /* for inet_aton */
 #include <ctype.h>     /* for isprint */
 #include <pcap.h>      /* for PCAP_ERRBUF_SIZE */
@@ -45,7 +47,8 @@
 #include <sys/time.h> /* for gettimeofday */
 #include <unistd.h>   /* for close */
 #ifdef __FreeBSD__
-#include <netinet/in.h>
+#  include <netinet/in.h>
+#  include <netinet/tcp.h>
 #endif
 
 #include "../misc/bpf_share.h"    /* for bpf_open_live */
@@ -73,6 +76,11 @@
 #else
 #define FIX(n) htons (n)
 #define UNFIX(n) ntohs (n)
+#endif
+
+#ifdef __FreeBSD__
+#define TCP_MSS_DEFAULT TCP6_MSS
+#define TCP_MSS_DESIRED TCP6_MSS
 #endif
 
 /*--------------[ cksum ]-----------------------------------------*/
