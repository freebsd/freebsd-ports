--- deaggregate.c.orig	2026-10-04 09:20:17 UTC
+++ deaggregate.c
@@ -24,6 +24,7 @@
 #include <netdb.h>
 #include <ctype.h>
 #include <assert.h>
+#include <sys/socket.h>
 
 #include "ipcalc.h"
 #include "ipv6.h"
