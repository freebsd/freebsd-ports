--- misc/pcap_openvas.h.orig	2015-08-03 10:14:29 UTC
+++ misc/pcap_openvas.h
@@ -26,6 +26,7 @@
 #ifndef OPENVAS_PCAP_H
 #define OPENVAS_PCAP_H
 
+#include <netinet/in.h>
 #include <pcap.h>
 
 int v6_is_local_ip (struct in6_addr *);
