--- src/openfiles.c.orig	Mon Apr 11 03:50:49 2005
+++ src/openfiles.c	Mon Apr 11 03:52:13 2005
@@ -8,6 +8,7 @@
 #include <netdb.h>
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 #include <arpa/inet.h>
 #include "procman.h"
 #include "openfiles.h"
