--- examples/gvncviewer.c.orig	2007-12-16 14:02:33.000000000 -0500
+++ examples/gvncviewer.c	2007-12-16 14:02:44.000000000 -0500
@@ -4,6 +4,7 @@
 #include <stdlib.h>
 #include <string.h>
 
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <netinet/tcp.h>
