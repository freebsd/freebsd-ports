$FreeBSD$
Add loopback support for FreeBSD.
author:  Radim Kolar

--- p0f.c.orig	Tue Feb 17 21:11:51 2004
+++ p0f.c	Tue Feb 17 21:10:48 2004
@@ -161,7 +161,8 @@
 
   switch(type) {
 
-    case DLT_NULL:
+    case DLT_NULL: header_len=4; break;
+
     case DLT_SLIP:
     case DLT_RAW:  break;
 
@@ -1199,11 +1200,15 @@
   /* Whoops, IP header ends past end_ptr */
   if ((_u8*)(iph + 1) > end_ptr) return;
 
-  if ( ((iph->ihl & 0x40) != 0x40) || iph->proto != IPPROTO_TCP) {
-    debug("[!] WARNING: Non-IP packet received. Bad header_len!\n");
+  if ( iph->proto != IPPROTO_TCP) {
+    debug("[!] WARNING: Non-IP packet received.\n");
     return;
   }
 
+  if ( ((iph->ihl & 0x40) != 0x40) ) {
+    debug("[!] WARNING: Bad header_len!\n");
+    return;
+  }
   /* If the declared length is shorter than the snapshot (etherleak
      or such), truncate this bad boy. */
 
@@ -1590,7 +1595,7 @@
     if (!use_iface) use_iface=pcap_lookupdev(errbuf);
 #endif /* ^WIN32 */
 
-    if (!use_iface) use_iface = "lo";
+    if (!use_iface) use_iface = "lo0";
 
     /* We do not rely on pcap timeouts - they suck really bad. Of
        course, the documentation sucks, and if you use the timeout
