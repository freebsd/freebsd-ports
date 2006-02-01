--- show_dump.c.orig	Mon Jul 12 07:21:09 2004
+++ show_dump.c	Wed Feb  1 18:07:01 2006
@@ -21,6 +21,7 @@
 #include <sys/param.h>
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <sys/ioctl.h>
 #include <sys/time.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
@@ -118,6 +119,7 @@
         bpf_u_int32 net;
         bpf_u_int32 mask;
 	char name[100], buf[256];
+	u_int v;
 
 	/* sanity check */
 	if (!ph || !ns) return -1;
@@ -141,6 +143,12 @@
 		if (!live_pcap) return -1;
 		if (pcap_setnonblock(live_pcap, 1, buf) < 0) {
 			screen_status("%s: %s", ph->name, buf);
+			show_dump_close();
+			return -1;
+		}
+		v = 1;
+		if (ioctl(pcap_fileno(live_pcap), BIOCIMMEDIATE, &v) < 0) {
+			screen_status("%s: %s", ph->name, strerror(errno));
 			show_dump_close();
 			return -1;
 		}
