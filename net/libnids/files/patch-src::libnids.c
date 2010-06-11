Description: Do not include the non-existent alloca.h header.
 I'll forward this patch next week after I write a configure test for it.
Forwarded: no
Author: Peter Pentchev <roam@FreeBSD.org>
Last-Update: 2010-06-011

--- src/libnids.c.orig
+++ src/libnids.c
@@ -14,7 +14,6 @@
 #include <stdlib.h>
 #include <string.h>
 #include <syslog.h>
-#include <alloca.h>
 #include <pcap.h>
 #include <errno.h>
 #include <config.h>
