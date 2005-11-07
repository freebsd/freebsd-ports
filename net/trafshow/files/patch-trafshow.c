--- trafshow.c.orig	Mon Jul 12 07:20:41 2004
+++ trafshow.c	Mon Nov  7 22:25:56 2005
@@ -305,7 +305,7 @@
 			fprintf(stderr, "%s: %s\n", dp->name, buf);
 			err++;
 		}
-		if (pcap_setnonblock(pd, 1, buf) < 0) {
+		if (pcap_setnonblock(pd, 0, buf) < 0) {
 			fprintf(stderr, "%s: %s\n", dp->name, buf);
 			pcap_close(pd);
 			err++;
