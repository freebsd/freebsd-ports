--- src/bsd/net.c.orig	2019-08-11 08:09:47 UTC
+++ src/bsd/net.c
@@ -124,6 +124,8 @@
 
 #include <sys/sysctl.h>
 
+#include "olsr_random.h"
+
 static int ignore_redir;
 static int send_redir;
 static int gateway;
