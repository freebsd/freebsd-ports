--- clog.c.orig	Thu Aug  7 21:56:32 1997
+++ clog.c	Sun Mar 24 02:33:49 2002
@@ -63,5 +63,5 @@
 /* some global variables (ugh!) */
 pcap_t *ip_socket;
-FILE *logfile = stdout;
+FILE *logfile;
 int resolve = 0;
 int dlt_len = 4;
@@ -92,4 +92,5 @@
    int c;
    
+   logfile = stdout;
    opterr = 0;
    /* parse arguments */
