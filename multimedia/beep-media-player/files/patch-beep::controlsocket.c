--- beep/controlsocket.c.orig	Mon Aug 23 21:23:19 2004
+++ beep/controlsocket.c	Mon Aug 23 21:27:43 2004
@@ -26,6 +26,7 @@
 
 #include <unistd.h>
 #include <errno.h>
+#include <sys/time.h>
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/un.h>
