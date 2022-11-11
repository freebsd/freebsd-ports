--- attack.c.orig	2022-11-08 17:21:47 UTC
+++ attack.c
@@ -40,6 +40,7 @@
 
 #ifdef STDC_HEADERS
 #include <stdio.h>
+#include <string.h>
 #endif
 #include <pcap.h>
 #include "attack.h"
