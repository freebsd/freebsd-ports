--- ngrep.c.orig	Fri Apr  9 13:09:16 2004
+++ ngrep.c	Fri Apr  9 13:09:22 2004
@@ -54,8 +54,8 @@
 #include <netinet/udp.h>
 #include <netinet/ip_icmp.h>
 
-#include <pcap.h>
 #include <net/bpf.h>
+#include <pcap.h>
 
 #include <stdlib.h>
 #include <string.h>
