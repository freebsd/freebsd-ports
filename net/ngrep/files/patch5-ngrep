--- ngrep.c.orig	Mon Dec 31 14:11:00 2001
+++ ngrep.c	Sat Nov  8 15:50:53 2003
@@ -62,6 +62,7 @@
 
 #include "ngrep.h"
 
+extern FILE *pcapyyin;
 
 static char rcsver[] = "$Revision: 1.23 $";
 
@@ -232,7 +233,7 @@
       filter = get_filter(&argv[optind-1]); 
 
 #ifdef NEED_RESTART
-      PCAP_RESTART();
+      PCAP_RESTART(pcapyyin);
 #endif
       if (pcap_compile(pd, &pcapfilter, filter, 0, mask.s_addr)) {
 	pcap_perror(pd, "pcap compile");
