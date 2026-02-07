--- rate_sta.c.orig	2003-08-20 14:31:53 UTC
+++ rate_sta.c
@@ -34,6 +34,7 @@
 #include <time.h>
 #include <pcap.h>
 #include "lib.h"
+#include "dns.h"
 #ifdef HAVE_REGEX
 #include <regex.h>
 #endif
