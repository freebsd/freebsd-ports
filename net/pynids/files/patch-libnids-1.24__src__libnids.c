--- ./libnids-1.24/src/libnids.c.orig	2010-12-21 16:52:15.158921317 -0500
+++ ./libnids-1.24/src/libnids.c	2010-12-21 16:52:24.455916662 -0500
@@ -14,7 +14,6 @@
 #include <stdlib.h>
 #include <string.h>
 #include <syslog.h>
-#include <alloca.h>
 #include <pcap.h>
 #include <errno.h>
 #include <config.h>
