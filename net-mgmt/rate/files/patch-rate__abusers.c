--- rate_abusers.c.orig	2003-08-20 15:42:14 UTC
+++ rate_abusers.c
@@ -33,6 +33,7 @@
 #include <time.h>
 #include <pcap.h>
 #include "lib.h"
+#include "dns.h"
 #ifdef HAVE_REGEX
 #include <regex.h>
 #endif
