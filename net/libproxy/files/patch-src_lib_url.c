--- src/lib/url.c.orig	2009-02-26 23:45:38.000000000 -0500
+++ src/lib/url.c	2009-02-26 23:47:25.000000000 -0500
@@ -25,6 +25,7 @@
 #include <unistd.h>
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 #include <arpa/inet.h>
 
 #include "misc.h"
