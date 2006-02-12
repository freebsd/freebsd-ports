--- p0f.c.orig	Sun Jul 11 02:17:57 2004
+++ p0f.c	Sun Feb 12 01:44:36 2006
@@ -1238,11 +1238,15 @@
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
 
@@ -1632,7 +1636,7 @@
     if (!use_iface) use_iface=pcap_lookupdev(errbuf);
 #endif /* ^WIN32 */
 
-    if (!use_iface) use_iface = "lo";
+    if (!use_iface) use_iface = "lo0";
 
     /* We do not rely on pcap timeouts - they suck really bad. Of
        course, the documentation sucks, and if you use the timeout
