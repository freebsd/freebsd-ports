--- arpscan.c.orig	Mon Aug 18 22:54:25 2003
+++ arpscan.c	Fri Sep 22 16:55:48 2006
@@ -8,7 +8,9 @@
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
+#include <err.h>
 #include <stdio.h>
+#include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
 
@@ -17,6 +19,13 @@
 
 #define PCAP_TIMEO 20
 
+#ifdef __FreeBSD__
+# include <sys/param.h>
+# if __FreeBSD_version > 500000
+#  define NTOHL(x) (x) = ntohl((u_int32_t)(x))
+# endif
+#endif
+
 struct	ether_arp {
 	struct	 arp_hdr ea_hdr;
 	u_int8_t arp_sha[ETH_ADDR_LEN];
@@ -36,7 +45,7 @@
 	fprintf(stderr, "\teg)\n");
 	fprintf(stderr, "\t    %s 172.16.1.11\n", __progname);
 	fprintf(stderr, "\t    %s 192.168.1.100-192.168.1.200\n", __progname);
-	fprintf(stderr, "\t    %s 172.16.1.41/29\n");
+	fprintf(stderr, "\t    %s 172.16.1.41/29\n", __progname);
 	fprintf(stderr, "\n");
 	exit(1);
 }
