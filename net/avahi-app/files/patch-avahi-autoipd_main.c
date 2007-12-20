--- avahi-autoipd/main.c.orig	2007-12-19 15:22:16.000000000 +0000
+++ avahi-autoipd/main.c	2007-12-19 15:23:39.000000000 +0000
@@ -64,8 +64,8 @@
 #include <pcap.h>
 
 /* Old versions of PCAP defined it as D_IN */
-#ifndef PCAP_D_IN
-#define PCAP_D_IN D_IN
+#ifndef D_IN
+#define D_IN PCAP_D_IN
 #endif
 
 #endif
