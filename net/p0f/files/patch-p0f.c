$FreeBSD$
On FreeBSD, the loopback interface is normally called lo0.
author:  Radim Kolar

--- p0f.c.orig	Mon Oct 13 18:57:21 2003
+++ p0f.c	Tue Feb 17 20:56:15 2004
@@ -1590,7 +1590,7 @@ int main(int argc,char** argv) {
     if (!use_iface) use_iface=pcap_lookupdev(errbuf);
 #endif /* ^WIN32 */
 
-    if (!use_iface) use_iface = "lo";
+    if (!use_iface) use_iface = "lo0";
 
     /* We do not rely on pcap timeouts - they suck really bad. Of
        course, the documentation sucks, and if you use the timeout
