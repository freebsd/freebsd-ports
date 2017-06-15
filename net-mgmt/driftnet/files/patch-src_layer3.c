--- src/layer3.c.orig	2013-05-12 15:16:43 UTC
+++ src/layer3.c
@@ -3,8 +3,12 @@
 #include <string.h>
 #include <assert.h>
 
+#include <sys/types.h>
+#include <netinet/in_systm.h>
+#include <netinet/in.h>
 #include <netinet/ip.h>
 #include <netinet/ip6.h>
+#include <sys/socket.h>
 
 #include "log.h"
 #include "layer3.h"
