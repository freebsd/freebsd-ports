--- src/bsd/net.c.orig	2016-06-22 12:04:33 UTC
+++ src/bsd/net.c
@@ -125,6 +125,8 @@
 
 #include <sys/sysctl.h>
 
+#include "olsr_random.h"
+
 static int ignore_redir;
 static int send_redir;
 static int gateway;
