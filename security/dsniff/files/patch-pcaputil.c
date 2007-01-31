--- ./pcaputil.c.orig	Tue Nov 14 12:51:08 2000
+++ ./pcaputil.c	Mon Sep 25 16:26:13 2006
@@ -13,9 +13,9 @@
 #include <stdlib.h>
 #include <string.h>
 #include <err.h>
-#include <pcap.h>
+#include </usr/include/pcap.h>
 #ifdef BSD
-#include <pcap-int.h>
+#include </usr/include/pcap-int.h>
 #endif
 #include "pcaputil.h"
 
