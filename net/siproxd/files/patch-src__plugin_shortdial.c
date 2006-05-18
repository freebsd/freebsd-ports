--- src/plugin_shortdial.c.orig	Sun Jan  1 21:31:31 2006
+++ src/plugin_shortdial.c	Mon May 15 11:50:12 2006
@@ -24,7 +24,7 @@
 //#include <errno.h>
 #include <string.h>
 //#include <stdlib.h>
-//#include <unistd.h>
+#include <unistd.h>
 //#include <signal.h>
 #include <netinet/in.h>
 //#include <arpa/inet.h>
