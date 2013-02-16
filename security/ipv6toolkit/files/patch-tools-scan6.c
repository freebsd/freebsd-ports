--- tools/scan6.c.orig	2013-02-17 06:55:02.000000000 +0900
+++ tools/scan6.c	2013-02-17 06:56:04.000000000 +0900
@@ -969,9 +969,11 @@
 	if(!pps_f && !bps_f)
 		pktinterval= 1000;
 
-
+#ifndef	IPV6TOOLKITCONF
+#define	IPV6TOOLKITCONF	"/etc/ipv6toolkit.conf"
+#endif
 	if(!configfile_f){
-		strncpy(configfile, "/etc/ipv6toolkit.conf", MAX_FILENAME_SIZE);
+		strncpy(configfile, IPV6TOOLKITCONF, MAX_FILENAME_SIZE);
 	}
 
 	if(tgt_vendor_f){
