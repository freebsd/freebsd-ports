--- process.c.orig	2016-04-16 01:18:17 UTC
+++ process.c
@@ -8,6 +8,7 @@
 
  */
 
+#include <stddef.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
@@ -22,6 +23,9 @@
 #include <arpa/inet.h>
 #include <sys/time.h>
 #include <sys/stat.h>
+#include <net/if.h>
+#include <net/pfvar.h>
+#include <net/if_pflog.h>
 
 #include "types.h"
 #include "config.h"
@@ -106,7 +110,7 @@ static void find_offset(const u8* data, s32 total_len)
     case DLT_LINUX_SLL:  link_off = 16; return;
 #endif /* DLT_LINUX_SLL */
 
-    case DLT_PFLOG:      link_off = 28; return;
+    case DLT_PFLOG:      link_off = PFLOG_HDRLEN; return;
 
     case DLT_IEEE802_11: link_off = 32; return;
   }
