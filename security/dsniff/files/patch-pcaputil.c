--- ./pcaputil.c.orig	2001-03-15 09:33:04.000000000 +0100
+++ ./pcaputil.c	2014-07-22 13:20:14.000000000 +0200
@@ -16,9 +16,10 @@
 #include <stdlib.h>
 #include <string.h>
 #include <err.h>
-#include <pcap.h>
+#include <net/bpf.h>
+#include </usr/include/pcap.h>
 #ifdef BSD
-#include <pcap-int.h>
+#include </usr/include/pcap-int.h>
 #endif
 
 #include "pcaputil.h"
