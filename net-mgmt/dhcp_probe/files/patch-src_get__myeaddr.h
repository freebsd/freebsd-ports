--- src/get_myeaddr.h.orig	2015-01-03 11:44:55.000000000 -0500
+++ src/get_myeaddr.h	2015-01-03 11:45:52.000000000 -0500
@@ -1,6 +1,6 @@
 #ifndef GET_MYEADDR_H
 #define GET_MYEADDR_H
 
-int get_myeaddr(int sockfd, struct in_addr *my_ipaddr, struct ether_addr *my_eaddr, const char *ifname);
+int get_myeaddr(int sockfd, struct in_addr *my_ipaddr, struct libnet_ether_addr *my_eaddr, const char *ifname);
 
 #endif /* not GET_MYEADDR_H */
