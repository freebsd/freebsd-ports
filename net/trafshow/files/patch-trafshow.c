--- trafshow.c.orig	Wed Apr 12 00:10:18 2006
+++ trafshow.c	Wed Apr 12 00:12:49 2006
@@ -20,6 +20,7 @@
 #endif
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <sys/ioctl.h>
 #ifdef	HAVE_PCAP_GET_SELECTABLE_FD
 #include <sys/select.h>
 #endif
@@ -307,6 +308,7 @@
 	const pcap_addr_t *ap;
 	PCAP_HANDLER *ph, *ph_prev = 0;
 	char *cp, buf[256];
+	int v = 1;
 
 	if (!ph_list) return -1;
 
@@ -334,6 +336,12 @@
 		}
 		if (pcap_setnonblock(pd, 1, buf) < 0) {
 			fprintf(stderr, "%s: %s\n", dp->name, buf);
+			pcap_close(pd);
+			err++;
+			continue;
+		}
+		if (ioctl(pcap_fileno(pd), BIOCIMMEDIATE, &v) < 0) {
+			fprintf(stderr, "%s: %s\n", dp->name, strerror(errno));
 			pcap_close(pd);
 			err++;
 			continue;
