--- nasl/nasl_packet_forgery_v6.c	2022-02-22 05:32:53.000000000 -0500
+++ nasl/nasl_packet_forgery_v6.c	2022-05-20 22:22:40.261563000 -0500
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
@@ -75,6 +78,11 @@
 #define UNFIX(n) ntohs (n)
 #endif
 
+#ifdef __FreeBSD__
+#define TCP_MSS_DEFAULT TCP6_MSS
+#define TCP_MSS_DESIRED TCP6_MSS
+#endif
+
 /*--------------[ cksum ]-----------------------------------------*/
 
 /*
@@ -2347,6 +2355,7 @@
   int dfl_len = get_int_var_by_name (lexic, "length", -1);
   struct script_infos *script_infos = lexic->script_infos;
   struct in6_addr *dstip = plug_get_host_ip (script_infos);
+  struct in6_addr tmp6_dst;
   int opt_on = 1;
   char name[INET6_ADDRSTRLEN];
   int allow_multicast = 0;
@@ -2430,7 +2439,9 @@
       /* if(b < 0) perror("sendto "); */
       if (b >= 0 && use_pcap != 0 && bpf >= 0)
         {
-          if (v6_islocalhost (&sip->ip6_dst))
+          tmp6_dst = sip->ip6_dst;
+
+          if (v6_islocalhost (&tmp6_dst))
             {
               answer = (u_char *) capture_next_v6_packet (bpf, to, &answer_sz);
               while (
