--- process.c.orig	2012-01-16 22:43:57.000000000 -0500
+++ process.c	2012-03-18 16:01:24.966689978 -0400
@@ -22,6 +22,9 @@
 #include <arpa/inet.h>
 #include <sys/time.h>
 #include <sys/stat.h>
+#include <net/if.h>
+#include <net/pfvar.h>
+#include <net/if_pflog.h>
 
 #include "types.h"
 #include "config.h"
@@ -106,7 +109,7 @@
     case DLT_LINUX_SLL:  link_off = 16; return;
 #endif /* DLT_LINUX_SLL */
 
-    case DLT_PFLOG:      link_off = 28; return;
+    case DLT_PFLOG:      link_off = PFLOG_HDRLEN; return;
 
     case DLT_IEEE802_11: link_off = 32; return;
   }
