--- plugins/rc/inputs.c.orig	Wed Apr  4 19:58:55 2007
+++ plugins/rc/inputs.c	Wed Apr  4 20:03:38 2007
@@ -8,6 +8,9 @@
 #include <sys/un.h>
 #endif
 
+#include <sys/types.h>
+#include <sys/socket.h>
+
 #include <sys/stat.h>
 
 #include <stdlib.h>
