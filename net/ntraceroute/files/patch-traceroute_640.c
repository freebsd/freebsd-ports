--- /usr/ports/distfiles/ntraceroute/traceroute_640.c	Sun Nov  6 15:43:00 2005
+++ ./traceroute_640.c	Wed Oct  4 11:07:20 2006
@@ -790,7 +790,7 @@
               struct icmp icmp_probe;
         } ip_payload;
 #endif /* V6.3.0 */
-};
+} __attribute__((packed));
 
 #ifdef SPRAY
 /*
