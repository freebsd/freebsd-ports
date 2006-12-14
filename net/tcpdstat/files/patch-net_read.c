--- net_read.orig	Wed Dec 13 23:11:59 2006
+++ net_read.c	Wed Dec 13 23:12:17 2006
@@ -137,7 +137,7 @@
 pcap_t *pd;
 int pcapfd;
 
-static int packet_length;		/* length of current packet */
+int packet_length;		/* length of current packet */
 
 #define STAT_ADD(name) \
     { tcpdstat[(name)].packets++; tcpdstat[(name)].bytes += packet_length; }
