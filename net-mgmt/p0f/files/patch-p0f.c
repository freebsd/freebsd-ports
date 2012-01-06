--- p0f.c.orig	2006-08-21 10:16:00.000000000 -0400
+++ p0f.c	2012-01-06 15:46:38.918380578 -0500
@@ -212,8 +212,11 @@
 #endif
 
 #ifdef DLT_PFLOG
+#include <net/if.h>
+#include <sys/queue.h>
+#include <net/if_pflog.h>
     case DLT_PFLOG:
-      header_len=28;
+      header_len=PFLOG_HDRLEN;
       break;
 #endif
 
@@ -1281,11 +1284,15 @@
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
 
@@ -1699,7 +1706,7 @@
     if (!use_iface) use_iface=pcap_lookupdev(errbuf);
 #endif /* ^WIN32 */
 
-    if (!use_iface) use_iface = "lo";
+    if (!use_iface) use_iface = "lo0";
 
     /* We do not rely on pcap timeouts - they suck really bad. Of
        course, the documentation sucks, and if you use the timeout
