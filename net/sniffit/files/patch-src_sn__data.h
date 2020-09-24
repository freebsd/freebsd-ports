--- src/sn_data.h.orig	2020-04-20 01:57:30 UTC
+++ src/sn_data.h
@@ -38,9 +38,9 @@ int HEADSIZE[]={0    ,14};		/* ppp: 4 or 0 or nothing 
 char *NETDEV[]={"ppp","ed"};
 int HEADSIZE[]={4    ,14};
 */
-#define NETDEV_NR      1
-char *NETDEV[]={"ed"};
-int HEADSIZE[]={14};
++#define NETDEV_NR      6
++char *NETDEV[]={"fxp","re","em","ppp","tun","lo"};
++int HEADSIZE[]={14   ,14  ,14  ,4    ,4    ,4   };
 #endif
 
 #ifdef BSDI				/* ppp: 4 or 0 ? */
@@ -155,7 +155,7 @@ char *SHARED, *connection_data, *timing, *running_conn
 						  *logged_connections;
 int *LISTlength, *DATAlength, memory_id;
 unsigned int  *TCP_nr_of_packets, *ICMP_nr_of_packets, *UDP_nr_of_packets;
-extern unsigned int  *IP_nr_of_packets;
+unsigned int  *IP_nr_of_packets;
 unsigned long *TCP_bytes_in_packets, *UDP_bytes_in_packets;
 int *DESC_LEN;
 
