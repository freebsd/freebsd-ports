--- arpscan.c.orig	Wed Aug  2 08:31:32 2006
+++ arpscan.c	Sun Sep 24 04:31:06 2006
@@ -9,7 +9,9 @@
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
+#include <err.h>
 #include <stdio.h>
+#include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
 #include <fcntl.h>
@@ -22,6 +24,13 @@
 #include <dnet.h>
 #endif /* DUMBNET */
 
+#ifdef __FreeBSD__
+# include <sys/param.h>
+# if __FreeBSD_version > 500000
+#  define NTOHL(x) (x) = ntohl((u_int32_t)(x))
+# endif
+#endif
+
 /* A concatenation of dnet's arp_hdr and arp_ethip. */
 struct ether_arp {
 	struct arp_hdr arp_hdr;
@@ -45,7 +54,7 @@
 	fprintf(stderr, "\teg)\n");
 	fprintf(stderr, "\t    %s 172.16.1.11\n", __progname);
 	fprintf(stderr, "\t    %s 192.168.1.100-192.168.1.200\n", __progname);
-	fprintf(stderr, "\t    %s 172.16.1.41/29\n");
+	fprintf(stderr, "\t    %s 172.16.1.41/29\n", __progname);
 	fprintf(stderr, "\n");
 	exit(1);
 }
