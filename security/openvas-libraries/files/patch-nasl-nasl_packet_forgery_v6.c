--- nasl/nasl_packet_forgery_v6.c.orig	2015-08-03 10:14:31 UTC
+++ nasl/nasl_packet_forgery_v6.c
@@ -43,6 +43,7 @@
 #include <string.h>             /* for bcopy */
 #include <sys/time.h>           /* for gettimeofday */
 #include <unistd.h>             /* for close */
+#include <netinet/in.h>
 #include <netinet/icmp6.h>      /* ICMPv6 */
 
 #include "bpf_share.h"          /* for bpf_open_live */
