--- ngrep.c.orig	Mon Jun 26 12:52:50 2000
+++ ngrep.c	Sat Aug 26 17:34:40 2000
@@ -48,6 +48,7 @@
 #include "regex.h"
 #include "ngrep.h"
 
+extern FILE *yyin;
 
 static char rcsver[] = "$Revision: 1.38 $";
 
@@ -196,7 +197,7 @@
       free(filter); 
       filter = get_filter(&argv[optind-1]); 
 
-      PCAP_RESTART();
+      PCAP_RESTART(yyin);
       if (pcap_compile(pd, &pcapfilter, filter, 0, mask.s_addr)) {
 	pcap_perror(pd, "pcap compile");
 	clean_exit(-1);
@@ -653,7 +654,7 @@
   struct tm *t = localtime(&h->ts.tv_sec);
 
   printf("%02d/%02d/%02d %02d:%02d:%02d.%06d ",
-	 t->tm_year+1900, t->tm_mon, t->tm_mday, t->tm_hour,
+	 t->tm_year+1900, t->tm_mon+1, t->tm_mday, t->tm_hour,
 	 t->tm_min, t->tm_sec, h->ts.tv_usec);
 }
 
