--- tools/scan6.c.orig	2015-04-05 14:03:21 UTC
+++ tools/scan6.c
@@ -1504,9 +1504,11 @@ int main(int argc, char **argv){
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
 
 	if(tgt_vendor_f || portscan_f){
