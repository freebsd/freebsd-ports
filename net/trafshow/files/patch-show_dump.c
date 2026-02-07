--- show_dump.c.orig	Wed Apr 12 00:16:51 2006
+++ show_dump.c	Wed Apr 12 00:18:21 2006
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
+	int v = 1;
 
 	/* sanity check */
 	if (!ph || !ns) return -1;
@@ -139,13 +141,16 @@
 		if (buf[0] != '\0')
 			screen_status("%s: %s", ph->name, buf);
 		if (!live_pcap) return -1;
-#ifdef	notdef
 		if (pcap_setnonblock(live_pcap, 1, buf) < 0) {
 			screen_status("%s: %s", ph->name, buf);
 			show_dump_close();
 			return -1;
 		}
-#endif
+		if (ioctl(pcap_fileno(live_pcap), BIOCIMMEDIATE, &v) < 0) {
+			screen_status("%s: %s", ph->name, strerror(errno));
+			show_dump_close();
+			return -1;
+		}
 		/* setup filter expression */
 		if (pcap_lookupnet(strcpy(name, ph->name), &net, &mask, buf) < 0) {
 			/* ignore error */
