--- aguri_pcap.c.orig	2003-03-12 15:09:45.000000000 +0100
+++ aguri_pcap.c	2009-03-27 08:57:57.000000000 +0100
@@ -35,6 +35,7 @@
 #include <sys/socket.h>
 #include <sys/ioctl.h>
 #include <net/if.h>
+#include <net/bpf.h>
 #include <netinet/in.h>
 #include <netinet/in_systm.h>
 #include <netinet/if_ether.h>
