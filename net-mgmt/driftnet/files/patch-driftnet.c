$FreeBSD$

--- driftnet.c.orig	Tue Sep 11 11:34:56 2001
+++ driftnet.c	Fri Mar  1 02:05:56 2002
@@ -14,7 +14,9 @@
 #include <assert.h>
 #include <errno.h>
 #include <pcap.h>
-#include <linux/if_ether.h>
+#include <sys/types.h>
+#include <netinet/in_systm.h>
+#include <netinet/in.h>
 #include <netinet/ip.h>
 #include <netinet/tcp.h>
 #include <stdlib.h>
@@ -261,8 +263,8 @@
 "Synopsis: driftnet -h | [-i interface] [-p] [-v] [filter code]\n"
 "\n"
 "  -h               Display this help message.\n"
-"  -i interface     Select the interface on which to listen (default: all\n"
-"                   interfaces).\n"
+"  -i interface     Select the interface on which to listen (default: first\n"
+"                   available interface).\n"
 "  -p               Do not put the listening interface into promiscuous mode.\n"
 "  -v               Verbose operation.\n"
 "\n"
@@ -293,7 +295,7 @@
 void setup_signals(void) {
     int *p;
     /* Signals to ignore. */
-    int ignore_signals[] = {SIGPIPE, 0};
+    int ignore_signals[] = {SIGPIPE, SIGCONT, SIGHUP, 0};
     /* Signals which mean we should quit, killing the display child if
      * applicable. */
     int terminate_signals[] = {SIGTERM, SIGINT, SIGSEGV, SIGBUS, SIGCHLD, 0};
@@ -393,6 +395,15 @@
         }
     }
     
+    if (!interface) {
+	interface = pcap_lookupdev(ebuf);
+
+	if (!interface) {
+	    fprintf(stderr, PROGNAME": pcap_lookupdev: %s\n", ebuf);
+	    return -1;
+	}
+    }
+
     
     if (verbose)
         fprintf(stderr, PROGNAME": listening on %s%s\n", interface ? interface : "all interfaces", promisc ? " in promiscuous mode" : "");
@@ -468,7 +479,7 @@
         fprintf(stderr, PROGNAME": link-level header length is %d bytes\n", pkt_offset);
 
     while (!foad) {
-        struct iphdr ip;
+        struct ip ip;
         struct tcphdr tcp;
         struct in_addr s, d;
         int off, len;
@@ -485,32 +496,32 @@
         fprintf(stderr, "packet len = %d captured = %d!\n", hdr.len, hdr.caplen);
 */
         memcpy(&ip, pkt + pkt_offset, sizeof(ip));
-        memcpy(&s, &ip.saddr, sizeof(ip.saddr));
-        memcpy(&d, &ip.daddr, sizeof(ip.daddr));
+        memcpy(&s, &ip.ip_src, sizeof(ip.ip_src));
+        memcpy(&d, &ip.ip_dst, sizeof(ip.ip_dst));
 
-        memcpy(&tcp, pkt + pkt_offset + (ip.ihl << 2), sizeof(tcp));
-        off = pkt_offset + (ip.ihl << 2) + (tcp.doff << 2);
+        memcpy(&tcp, pkt + pkt_offset + (ip.ip_hl << 2), sizeof(tcp));
+        off = pkt_offset + (ip.ip_hl << 2) + (tcp.th_off << 2);
         len = hdr.caplen - off;
 
         /*
         if (verbose)
-            fprintf(stderr, PROGNAME": captured packet: %s:%d -> %s:%d\n", inet_ntoa(s), ntohs(tcp.source), inet_ntoa(d), ntohs(tcp.dest));
+            fprintf(stderr, PROGNAME": captured packet: %s:%d -> %s:%d\n", inet_ntoa(s), ntohs(tcp.th_sport), inet_ntoa(d), ntohs(tcp.th_dport));
         */
         
         /* XXX fragmented packets and other nasties. */
         
         /* try to find the connection slot associated with this. */
-        C = find_connection(&s, &d, ntohs(tcp.source), ntohs(tcp.dest));
+        C = find_connection(&s, &d, ntohs(tcp.th_sport), ntohs(tcp.th_dport));
 
         /* no connection at all, so we need to allocate one. */
         if (!C) {
             if (verbose)
-                fprintf(stderr, PROGNAME": new connection: %s\n", connection_string(s, ntohs(tcp.source), d, ntohs(tcp.dest)));
+                fprintf(stderr, PROGNAME": new connection: %s\n", connection_string(s, ntohs(tcp.th_sport), d, ntohs(tcp.th_dport)));
             C = alloc_connection();
-            *C = connection_new(&s, &d, ntohs(tcp.source), ntohs(tcp.dest));
+            *C = connection_new(&s, &d, ntohs(tcp.th_sport), ntohs(tcp.th_dport));
             /* This might or might not be an entirely new connection (SYN flag
              * set). Either way we need a sequence number to start at. */
-            (*C)->isn = ntohl(tcp.seq);
+            (*C)->isn = ntohl(tcp.th_seq);
         }
 
         /* Now we need to process this segment. */
@@ -526,16 +537,16 @@
             c->isn = htonl(tcp.seq);
 #endif
 
-        if (tcp.rst) {
+        if (tcp.th_flags & TH_RST) {
             /* Looks like this connection is bogus, and so might be a
              * connection going the other way. */
             if (verbose)
-                fprintf(stderr, PROGNAME": connection reset: %s\n", connection_string(s, ntohs(tcp.source), d, ntohs(tcp.dest)));
+                fprintf(stderr, PROGNAME": connection reset: %s\n", connection_string(s, ntohs(tcp.th_sport), d, ntohs(tcp.th_dport)));
             
             connection_delete(c);
             *C = NULL;
 
-            if ((C = find_connection(&d, &s, ntohs(tcp.dest), ntohs(tcp.source)))) {
+            if ((C = find_connection(&d, &s, ntohs(tcp.th_dport), ntohs(tcp.th_sport)))) {
                 connection_delete(*C);
                 *C = NULL;
             }
@@ -547,7 +558,7 @@
             /* We have some data in the packet. If this data occurred after
              * the first data we collected for this connection, then save it
              * so that we can look for images. Otherwise, discard it. */
-            unsigned int offset = ntohl(tcp.seq);
+            unsigned int offset = ntohl(tcp.th_seq);
 
             /* Modulo 2**32 arithmetic; offset = seq - isn + delta. */
             if (offset < (c->isn + delta))
@@ -558,19 +569,19 @@
             if (offset > c->len + 262144) {
                 /* Out-of-order packet. */
                 if (verbose) 
-                    fprintf(stderr, PROGNAME": out of order packet: %s\n", connection_string(s, ntohs(tcp.source), d, ntohs(tcp.dest)));
+                    fprintf(stderr, PROGNAME": out of order packet: %s\n", connection_string(s, ntohs(tcp.th_sport), d, ntohs(tcp.th_dport)));
             } else {
 /*                if (verbose)
-                    fprintf(stderr, PROGNAME": captured %d bytes: %s:%d -> %s:%d\n", (int)len, inet_ntoa(s), ntohs(tcp.source), inet_ntoa(d), ntohs(tcp.dest));*/
+                    fprintf(stderr, PROGNAME": captured %d bytes: %s:%d -> %s:%d\n", (int)len, inet_ntoa(s), ntohs(tcp.th_sport), inet_ntoa(d), ntohs(tcp.th_dport));*/
                 connection_push(c, pkt + off, offset, len);
                 connection_harvest_images(c);
             }
         }
 
-        if (tcp.fin) {
+        if (tcp.th_flags & TH_FIN) {
             /* Connection closing. */
             if (verbose)
-                fprintf(stderr, PROGNAME": connection closing: %s, %d bytes transferred\n", connection_string(s, ntohs(tcp.source), d, ntohs(tcp.dest)), c->len);
+                fprintf(stderr, PROGNAME": connection closing: %s, %d bytes transferred\n", connection_string(s, ntohs(tcp.th_sport), d, ntohs(tcp.th_dport)), c->len);
             connection_harvest_images(c);
             connection_delete(c);
             *C = NULL;
