--- src/sniffer.c.orig	Tue May 11 18:00:24 2004
+++ src/sniffer.c	Tue May 11 18:03:48 2004
@@ -1,7 +1,9 @@
 #ifdef USE_PCAP
 
 #include <pcap.h>
+#ifndef __FreeBSD__
 #include <net/dlt.h>
+#endif
 #include <stdio.h>
 extern char *iface1;
 #define BUFSIZE 65540
