--- protocols/tcp/nd_tcb.c.orig	Sun Oct 13 21:42:08 2002
+++ protocols/tcp/nd_tcb.c	Sun Oct 13 21:45:35 2002
@@ -26,13 +26,15 @@
 #  include <config.h>
 #endif
 
+#include <sys/types.h>
+#include <netinet/in_systm.h>
+#include <netinet/in.h>
 #include <netinet/ip.h>
 
 #include <string.h>
 #include <unistd.h>
 #include <stdlib.h>
 #include <stdio.h>
-#include <sys/types.h>
 #include <glib.h>
 
 #include <netdude/nd.h>
