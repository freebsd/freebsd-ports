--- ngrep-lib.c.orig	Sat Feb 28 22:23:31 2004
+++ ngrep-lib.c	Sat Feb 28 22:23:46 2004
@@ -51,6 +51,7 @@
 #include <netinet/udp.h>
 #include <netinet/ip_icmp.h>
 
+#define PCAP_DONT_INCLUDE_PCAP_BPF_H
 #include <pcap.h>
 #include <net/bpf.h>
 
