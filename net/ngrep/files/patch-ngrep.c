--- ngrep.c.orig	Fri Oct 22 05:21:26 1999
+++ ngrep.c	Mon Jan 31 12:58:36 2000
@@ -59,6 +59,7 @@
 int link_offset;
 pcap_t *pd;
 
+extern FILE *yyin;
 
 int main(int argc, char **argv) {
   char c;
@@ -141,7 +142,7 @@
       free(filter); 
       filter = get_filter(&argv[optind-1]); 
 
-      PCAP_RESTART();
+      PCAP_RESTART(yyin);
       if (pcap_compile(pd,&pcapfilter,filter,0,mask.s_addr)) {
 	pcap_perror(pd,"pcap compile");
 	exit(-1);
