--- ./hexinject.c.orig	2011-06-11 15:56:47.000000000 +0200
+++ ./hexinject.c	2011-06-28 18:11:46.000000000 +0200
@@ -678,8 +678,8 @@
     }
 
     /* Set read timeout */
-    if(pcap_set_timeout(fp, -1) != 0) {
-        fprintf(stderr,"Unable to set read timeout: the interface may be already activated\n");
+    if(pcap_set_timeout(fp, 1000) != 0) {
+        fprintf(stderr,"Unable to set read timeout: the interface may be already activated (%s)\n", errbuf);
         return 1;
     }
 
