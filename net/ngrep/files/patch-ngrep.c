--- ngrep.c.orig	Wed Aug  8 23:36:09 2001
+++ ngrep.c	Wed Aug  8 23:36:31 2001
@@ -62,6 +62,7 @@
 
 #include "ngrep.h"
 
+extern FILE *yyin;
 
 static char rcsver[] = "$Revision: 1.18 $";
 
@@ -232,7 +233,7 @@
       filter = get_filter(&argv[optind-1]); 
 
 #ifdef NEED_RESTART
-      PCAP_RESTART();
+      PCAP_RESTART(yyin);
 #endif
       if (pcap_compile(pd, &pcapfilter, filter, 0, mask.s_addr)) {
 	pcap_perror(pd, "pcap compile");
