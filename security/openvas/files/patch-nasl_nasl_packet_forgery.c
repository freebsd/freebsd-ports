--- nasl/nasl_packet_forgery.c	2021-04-15 09:39:00.000000000 -0500
+++ nasl/nasl_packet_forgery.c	2021-06-14 20:22:38.283404000 -0500
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
@@ -163,7 +174,7 @@
   if (s != NULL)
     inet_aton (s, &pkt->ip_dst);
   else
-    pkt->ip_dst.s_addr = dst_addr->s6_addr32[3];
+    memcpy(&pkt->ip_dst.s_addr, &dst_addr->s6_addr[12], 4);
 
   if (data != NULL)
     {
@@ -2086,7 +2097,7 @@
 
   if (dst == NULL || (IN6_IS_ADDR_V4MAPPED (dst) != 1))
     return NULL;
-  inaddr.s_addr = dst->s6_addr32[3];
+  memcpy(&inaddr.s_addr, &dst->s6_addr[12], 4);
   for (i = 0; i < sizeof (sports) / sizeof (int); i++)
     {
       if (sports[i] == 0)
@@ -2104,7 +2115,7 @@
     port = plug_get_host_open_port (script_infos);
 
   if (islocalhost (&inaddr) > 0)
-    src.s_addr = dst->s6_addr32[3];
+    memcpy(&src.s_addr, &dst->s6_addr[12], 4);
   else
     {
       bzero (&src, sizeof (src));
@@ -2229,7 +2240,7 @@
 
   if (dstip == NULL || (IN6_IS_ADDR_V4MAPPED (dstip) != 1))
     return NULL;
-  inaddr.s_addr = dstip->s6_addr32[3];
+  memcpy(&inaddr.s_addr, &dstip->s6_addr[12], 4);
   soc = socket (AF_INET, SOCK_RAW, IPPROTO_RAW);
   if (soc < 0)
     return NULL;
@@ -2369,7 +2380,7 @@
         {
           struct in_addr src;
           bzero (&src, sizeof (src));
-          inaddr.s_addr = dst->s6_addr32[3];
+	  memcpy(&inaddr.s_addr, &dst->s6_addr[12], 4);
           interface = routethrough (&inaddr, &src);
         }
       else
@@ -2518,7 +2529,7 @@
         {
           struct in_addr src;
           bzero (&src, sizeof (src));
-          inaddr.s_addr = dst->s6_addr32[3];
+	  memcpy(&inaddr.s_addr, &dst->s6_addr[12], 4);
           interface = routethrough (&inaddr, &src);
         }
       else
