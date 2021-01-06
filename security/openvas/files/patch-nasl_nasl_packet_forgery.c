--- nasl/nasl_packet_forgery.c	2020-08-11 07:00:25.000000000 -0500
+++ nasl/nasl_packet_forgery.c	2021-01-04 17:38:44.560650000 -0500
@@ -33,6 +33,8 @@
 #include "nasl_tree.h"
 #include "nasl_var.h"
 
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <arpa/inet.h> /* for inet_aton */
 #include <ctype.h>     /* for isprint */
 #include <errno.h>     /* for errno */
@@ -136,7 +138,7 @@
   if (s != NULL)
     inet_aton (s, &pkt->ip_dst);
   else
-    pkt->ip_dst.s_addr = dst_addr->s6_addr32[3];
+    memcpy(&pkt->ip_dst.s_addr, &dst_addr->s6_addr[12], 4);
 
   if (data != NULL)
     {
@@ -1283,7 +1285,7 @@
 
   if (dst == NULL || (IN6_IS_ADDR_V4MAPPED (dst) != 1))
     return NULL;
-  inaddr.s_addr = dst->s6_addr32[3];
+  memcpy(&inaddr.s_addr, &dst->s6_addr[12], 4);
   for (i = 0; i < sizeof (sports) / sizeof (int); i++)
     {
       if (sports[i] == 0)
@@ -1301,7 +1303,7 @@
     port = plug_get_host_open_port (script_infos);
 
   if (islocalhost (&inaddr) > 0)
-    src.s_addr = dst->s6_addr32[3];
+    memcpy(&src.s_addr, &dst->s6_addr[12], 4);
   else
     {
       bzero (&src, sizeof (src));
@@ -1411,7 +1413,7 @@
 
   if (dstip == NULL || (IN6_IS_ADDR_V4MAPPED (dstip) != 1))
     return NULL;
-  inaddr.s_addr = dstip->s6_addr32[3];
+  memcpy(&inaddr.s_addr, &dstip->s6_addr[12], 4);
   soc = socket (AF_INET, SOCK_RAW, IPPROTO_RAW);
   if (soc < 0)
     return NULL;
@@ -1540,7 +1542,7 @@
         {
           struct in_addr src;
           bzero (&src, sizeof (src));
-          inaddr.s_addr = dst->s6_addr32[3];
+  	  memcpy(&inaddr.s_addr, &dst->s6_addr[12], 4);
           interface = routethrough (&inaddr, &src);
         }
       else
@@ -1680,7 +1682,7 @@
         {
           struct in_addr src;
           bzero (&src, sizeof (src));
-          inaddr.s_addr = dst->s6_addr32[3];
+	  memcpy(&inaddr.s_addr, &dst->s6_addr[12], 4);
           interface = routethrough (&inaddr, &src);
         }
       else
