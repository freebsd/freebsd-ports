--- trafshow.c.orig	Sun Jan  8 08:05:29 2006
+++ trafshow.c	Wed Feb  1 18:07:33 2006
@@ -20,6 +20,7 @@
 #endif
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <sys/ioctl.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <signal.h>
@@ -281,6 +282,7 @@
 	pcap_t *pd;
 	PCAP_HANDLER *ph, *ph_prev = 0;
 	char buf[256];
+	u_int v;
 
 	if (!ph_list) return -1;
 
@@ -307,6 +309,13 @@
 		}
 		if (pcap_setnonblock(pd, 1, buf) < 0) {
 			fprintf(stderr, "%s: %s\n", dp->name, buf);
+			pcap_close(pd);
+			err++;
+			continue;
+		}
+		v = 1;
+		if (ioctl(pcap_fileno(pd), BIOCIMMEDIATE, &v) < 0) {
+			fprintf(stderr, "%s: %s\n", dp->name, strerror(errno));
 			pcap_close(pd);
 			err++;
 			continue;
