--- xinetd/sensor.c.orig	Mon Aug 19 11:53:03 2002
+++ xinetd/sensor.c	Mon Aug 19 11:53:15 2002
@@ -4,6 +4,7 @@
  * and conditions for redistribution.
  */
 
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <time.h>
 
