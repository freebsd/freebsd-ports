--- lft.c.orig	Wed May  7 15:43:30 2003
+++ lft.c	Tue Sep 30 05:24:47 2003
@@ -25,6 +25,8 @@
 #include "acconfig.h"
 #include <assert.h>
 
+#define INT_MAX ((int))~0U>>1))
+
 #ifdef __CYGWIN__
 #define __USE_W32_SOCKETS
 #include "windows.h"
@@ -76,6 +78,12 @@
 #ifdef BSD
 #include <machine/limits.h>
 #endif
+#ifdef BSD_IP_STACK
+#include <errno.h>
+#include <sys/ioctl.h>
+#include <net/bpf.h>
+#include <pcap-int.h>
+#endif
 
 #ifdef sun
 #include <limits.h>
@@ -961,7 +969,7 @@
       	return; * not for us */
 
 
-    if (noisy) printf ("ICMP SEQ=%u received\n", ntohl (tcp->th_seq));
+    if (noisy) printf ("ICMP SEQ=%lu received\n", ntohl (tcp->th_seq));
     recv_packet (ntohl (tcp->th_seq) , orig_ip->ip_src,
 		 (icmp->icmp_type == ICMP_TIMXCEED) ? -2 : icmp->icmp_code);
     break;
@@ -1046,6 +1054,9 @@
 	   "LFT version 2.2 2003/05/07 compiled for " HOST_SYSTEM_TYPE "\n\n"
 	   "    Compile-time options:\n\n"
 #if defined(BSD_IP_STACK)
+	   "      + BSDSTACK\n"
+#endif
+#if defined(BSD)
 	   "      + BSD\n"
 #endif
 #if defined(linux)
@@ -1111,6 +1122,7 @@
   int use_fins = 0;
   char *cp;
   struct timeval tb;
+  unsigned int bpfimmflag;
 
   setbuf (stdout, NULL);
 
@@ -1131,7 +1143,7 @@
       dport = atoi (optarg);
       break;
     case 'q':
-      seq_start = atol (optarg);
+      seq_start = strtoll (optarg, NULL, 10);
       break;
     case 'w':
       win_len = atoi(optarg);
@@ -1311,6 +1323,13 @@
     fprintf (stderr, "%s\n", ebuf);
     exit (1);
   }
+#ifdef BSD_IP_STACK
+  bpfimmflag = 1;
+  if ( ioctl(pd->fd, BIOCIMMEDIATE, &bpfimmflag) < 0) {
+    fprintf(stderr, "BIOCIMMEDIATE: %s",
+    pcap_strerror(errno));
+  }
+#endif
 #endif
   init_address (hostname, pcap_dev);
   open_sockets ();
