--- ./traceroute.c.orig	2011-10-19 10:04:10.000000000 -0400
+++ ./traceroute.c	2011-10-19 10:04:08.000000000 -0400
@@ -2,6 +2,7 @@
 /*
  *  STILL BROKEN: traceroute -g on linux (LSRR)
  */
+#include <string.h>
 #define TRACE_TOS 1
 #define SPRAY
 #define FIXT
@@ -798,7 +799,7 @@
               struct icmp icmp_probe;
         } ip_payload;
 #endif /* V6.3.0 */
-};
+} __attribute__((packed));
 
 #ifdef SPRAY
 /*
