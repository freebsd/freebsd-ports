--- pcaputil.h.orig	Thu Jan 17 22:33:55 2002
+++ pcaputil.h	Mon Dec  5 13:26:13 2005
@@ -9,6 +9,10 @@
 #ifndef PCAPUTIL_H
 #define PCAPUTIL_H
 
+#ifndef BIOCIMMEDIATE
+#define BIOCIMMEDIATE _IOW('B',112,u_int)
+#endif
+
 pcap_t *pcap_open(char *device);
 int	pcap_dloff(pcap_t *pcap);
 int	pcap_filter(pcap_t *pcap, const char *fmt, ...);
