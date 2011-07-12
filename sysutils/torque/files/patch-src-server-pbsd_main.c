--- src/server/pbsd_main.c.orig	2011-06-24 13:24:45.000000000 -0500
+++ src/server/pbsd_main.c	2011-06-24 13:25:15.000000000 -0500
@@ -94,6 +94,7 @@
 #include <sys/lock.h>
 #endif /* PLOCK_DAEMONS */
 #include <netinet/in.h>
+#include <sys/socket.h>
 #include "pbs_ifl.h"
 #include <assert.h>
 #include <ctype.h>
