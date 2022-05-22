--- nasl/nasl_packet_forgery.c	2022-02-22 05:32:53.000000000 -0500
+++ nasl/nasl_packet_forgery.c	2022-05-20 22:17:07.796127000 -0500
@@ -33,6 +33,12 @@
 #include "nasl_tree.h"
 #include "nasl_var.h"
 
+#include <sys/types.h>
+#include <sys/socket.h>
+#ifdef __FreeBSD
+  #include <netinet/in.h>
+  #include <netinet/tcp.h>
+#endif
 #include <arpa/inet.h> /* for inet_aton */
 #include <ctype.h>     /* for isprint */
 #include <errno.h>     /* for errno */
@@ -52,6 +58,11 @@
 #define UNFIX(n) ntohs (n)
 #endif
 
+#ifdef __FreeBSD__
+#define TCP_MSS_DEFAULT TCP_MSS
+#define TCP_MSS_DESIRED TCP_MSS
+#endif
+
 /*--------------[ cksum ]-----------------------------------------*/
 
 /*
@@ -119,6 +130,7 @@
   struct in6_addr *dst_addr;
   char *data;
   int data_len;
+  struct in_addr tmp_src, tmp_dst;
 
   dst_addr = plug_get_host_ip (script_infos);
 
@@ -153,17 +165,21 @@
   pkt->ip_sum = htons (get_int_var_by_name (lexic, "ip_sum", 0));
   /* source */
   s = get_str_var_by_name (lexic, "ip_src");
-  if (s != NULL)
-    inet_aton (s, &pkt->ip_src);
+  if (s != NULL) {
+    inet_aton (s, &tmp_src);
+    pkt->ip_src = tmp_src;
+  }
   /* else this host address? */
 
   /* I know that this feature looks dangerous, but anybody can edit an IP
    * packet with the string functions */
   s = get_str_var_by_name (lexic, "ip_dst");
-  if (s != NULL)
-    inet_aton (s, &pkt->ip_dst);
+  if (s != NULL) {
+    inet_aton (s, &tmp_dst);
+    pkt->ip_dst = tmp_dst;
+  }
   else
-    pkt->ip_dst.s_addr = dst_addr->s6_addr32[3];
+    memcpy(&pkt->ip_dst.s_addr, &dst_addr->s6_addr[12], 4);
 
   if (data != NULL)
     {
@@ -314,6 +330,7 @@
   int size = get_var_size_by_name (lexic, "ip");
   tree_cell *retc;
   struct ip *pkt;
+  struct in_addr tmp_src;
   char *s;
 
   if (o_pkt == NULL)
@@ -337,9 +354,10 @@
   pkt->ip_p = get_int_var_by_name (lexic, "ip_p", pkt->ip_p);
 
   s = get_str_var_by_name (lexic, "ip_src");
-  if (s != NULL)
-    inet_aton (s, &pkt->ip_src);
-
+  if (s != NULL) {
+    inet_aton (s, &tmp_src);
+    pkt->ip_src = tmp_src;
+  }
   pkt->ip_sum = htons (get_int_var_by_name (lexic, "ip_sum", 0));
   if (pkt->ip_sum == 0)
     pkt->ip_sum = np_in_cksum ((u_short *) pkt, sizeof (struct ip));
@@ -2088,7 +2106,7 @@
 
   if (dst == NULL || (IN6_IS_ADDR_V4MAPPED (dst) != 1))
     return NULL;
-  inaddr.s_addr = dst->s6_addr32[3];
+  memcpy(&inaddr.s_addr, &dst->s6_addr[12], 4);
   for (i = 0; i < sizeof (sports) / sizeof (int); i++)
     {
       if (sports[i] == 0)
@@ -2106,7 +2124,7 @@
     port = plug_get_host_open_port (script_infos);
 
   if (islocalhost (&inaddr) > 0)
-    src.s_addr = dst->s6_addr32[3];
+    memcpy(&src.s_addr, &dst->s6_addr[12], 4);
   else
     {
       bzero (&src, sizeof (src));
@@ -2226,12 +2244,12 @@
   int opt_on = 1;
   struct script_infos *script_infos = lexic->script_infos;
   struct in6_addr *dstip = plug_get_host_ip (script_infos);
-  struct in_addr inaddr;
+  struct in_addr inaddr, tmp_dst;
   int allow_broadcast = 0;
 
   if (dstip == NULL || (IN6_IS_ADDR_V4MAPPED (dstip) != 1))
     return NULL;
-  inaddr.s_addr = dstip->s6_addr32[3];
+  memcpy(&inaddr.s_addr, &dstip->s6_addr[12], 4);
   soc = socket (AF_INET, SOCK_RAW, IPPROTO_RAW);
   if (soc < 0)
     return NULL;
@@ -2302,7 +2320,8 @@
       /* if(b < 0) perror("sendto "); */
       if (b >= 0 && use_pcap != 0 && bpf >= 0)
         {
-          if (islocalhost (&sip->ip_dst))
+	  tmp_dst = sip->ip_dst;
+          if (islocalhost (&tmp_dst))
             {
               answer = (u_char *) capture_next_packet (bpf, to, &answer_sz);
               while (answer != NULL
@@ -2371,7 +2390,7 @@
         {
           struct in_addr src;
           bzero (&src, sizeof (src));
-          inaddr.s_addr = dst->s6_addr32[3];
+	  memcpy(&inaddr.s_addr, &dst->s6_addr[12], 4);
           interface = routethrough (&inaddr, &src);
         }
       else
@@ -2520,7 +2539,7 @@
         {
           struct in_addr src;
           bzero (&src, sizeof (src));
-          inaddr.s_addr = dst->s6_addr32[3];
+	  memcpy(&inaddr.s_addr, &dst->s6_addr[12], 4);
           interface = routethrough (&inaddr, &src);
         }
       else
