--- src/server/req_getcred.c.orig	2012-07-15 11:42:07.000000000 -0500
+++ src/server/req_getcred.c	2012-07-15 11:48:39.000000000 -0500
@@ -97,6 +97,7 @@
 #include <ctype.h>
 #include <netdb.h>
 #include <signal.h>
+#include <netinet/in.h>
 #include "libpbs.h"
 #include "log.h"
 #include "server_limits.h"
