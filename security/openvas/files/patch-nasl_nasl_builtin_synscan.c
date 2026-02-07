--- nasl/nasl_builtin_synscan.c	2020-08-11 07:00:25.000000000 -0500
+++ nasl/nasl_builtin_synscan.c	2021-01-04 17:11:12.118080000 -0500
@@ -36,6 +36,8 @@
 #include <arpa/inet.h> /* for AF_INET */
 #include <gvm/base/logging.h>
 #include <gvm/base/prefs.h> /* for prefs_get */
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <netinet/ip.h>
 #include <netinet/tcp.h> /* for TH_SYN */
 #include <stdlib.h>      /* for rand() */
@@ -699,7 +701,7 @@
   if (IN6_IS_ADDR_V4MAPPED (dst6))
     {
       family = AF_INET;
-      dst.s_addr = dst6->s6_addr32[3];
+      dst.s_addr = dst6->s6_addr[12];
       soc = rawsocket (AF_INET);
     }
   else
@@ -787,7 +789,7 @@
   struct in_addr *dst;
   struct in_addr inaddr;
 
-  inaddr.s_addr = dst6->s6_addr32[3];
+  inaddr.s_addr = dst6->s6_addr[12];
   dst = &inaddr;
 
   if (islocalhost (dst))
