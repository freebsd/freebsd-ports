--- lib/conntrack.c.orig	2017-11-29 15:45:30 UTC
+++ lib/conntrack.c
@@ -17,10 +17,10 @@
 #include <config.h>
 #include <ctype.h>
 #include <errno.h>
+#include <sys/types.h>
 #include <netinet/in.h>
 #include <netinet/icmp6.h>
 #include <string.h>
-#include <sys/types.h>
 
 #include "bitmap.h"
 #include "conntrack.h"
