- DSCP cannot be modified on FreeBSD yet
src/tcp.c:61:14: error: use of undeclared identifier 'IPTOS_DSCP_MASK'
  v = dscp & IPTOS_DSCP_MASK;

- Change include order for FreeBSD
In file included from src/tcp.c:33:
/usr/include/netinet/ip.h:69:17: error: field has incomplete type 'struct in_addr'
        struct  in_addr ip_src,ip_dst;  /* source and dest address */
                        ^
/usr/include/netinet/ip.h:69:9: note: forward declaration of 'struct in_addr'
        struct  in_addr ip_src,ip_dst;  /* source and dest address */
                ^
/usr/include/netinet/ip.h:69:24: error: field has incomplete type 'struct in_addr'
        struct  in_addr ip_src,ip_dst;  /* source and dest address */
                               ^
/usr/include/netinet/ip.h:69:9: note: forward declaration of 'struct in_addr'
        struct  in_addr ip_src,ip_dst;  /* source and dest address */
                ^
/usr/include/netinet/ip.h:181:19: error: field has incomplete type 'struct in_addr'
                        struct in_addr ipt_addr;
                                       ^
/usr/include/netinet/ip.h:69:9: note: forward declaration of 'struct in_addr'
        struct  in_addr ip_src,ip_dst;  /* source and dest address */
                ^
/usr/include/netinet/ip.h:216:17: error: field has incomplete type 'struct in_addr'
        struct  in_addr ippseudo_src;   /* source internet address */
                        ^
/usr/include/netinet/ip.h:69:9: note: forward declaration of 'struct in_addr'
        struct  in_addr ip_src,ip_dst;  /* source and dest address */
                ^
/usr/include/netinet/ip.h:217:17: error: field has incomplete type 'struct in_addr'
        struct  in_addr ippseudo_dst;   /* destination internet address */
                        ^
/usr/include/netinet/ip.h:69:9: note: forward declaration of 'struct in_addr'
        struct  in_addr ip_src,ip_dst;  /* source and dest address */
                ^
--- src/tcp.c.orig	2017-01-20 19:41:51.000000000 +0100
+++ src/tcp.c	2017-02-08 11:15:26.836727000 +0100
@@ -30,8 +30,8 @@
 #include <fcntl.h>
 #include <errno.h>
 #include <signal.h>
-#include <netinet/ip.h>
 #include <netinet/in.h>
+#include <netinet/ip.h>
 #include <netinet/tcp.h>
 #include <arpa/inet.h>
 
@@ -56,6 +56,7 @@
 int
 socket_set_dscp(int sockfd, uint32_t dscp, char *errbuf, size_t errbufsize)
 {
+#ifdef IPTOS_DSCP_MASK
   int r, v;
 
   v = dscp & IPTOS_DSCP_MASK;
@@ -65,6 +66,7 @@
       snprintf(errbuf, errbufsize, "IP_TOS failed: %s", strerror(errno));
     return -1;
   }
+#endif
   return 0;
 }
 
