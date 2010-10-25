--- ./hexinject.c.orig	2010-10-24 06:23:57.000000000 +0200
+++ ./hexinject.c	2010-10-24 06:24:17.000000000 +0200
@@ -424,7 +424,7 @@
     if ( (fp = pcap_open_live( options.device, // name of the device
                                BUFSIZ,         // portion of the packet to capture
                                1,              // promiscuous mode
-                               -1,             // read timeout
+                               1000,             // read timeout
                                errbuf          // error buffer
                               )) == NULL)
 
