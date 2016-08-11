--- tmate-proxy.c.orig	2016-04-26 08:05:24 UTC
+++ tmate-proxy.c
@@ -2,6 +2,7 @@
 #include <netinet/tcp.h>
 #include <fcntl.h>
 #include <errno.h>
+#include <netinet/in.h>
 
 #include "tmate.h"
 #include "tmate-protocol.h"
