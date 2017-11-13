--- avahi-autoipd/main.c.orig	2010-08-26 00:51:38 UTC
+++ avahi-autoipd/main.c
@@ -62,8 +62,8 @@
 #include <pcap.h>
 
 /* Old versions of PCAP defined it as D_IN */
-#ifndef PCAP_D_IN
-#define PCAP_D_IN D_IN
+#ifndef D_IN
+#define D_IN PCAP_D_IN
 #endif
 
 #endif
