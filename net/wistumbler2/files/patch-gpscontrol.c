--- src/gpscontrol.c.orig	Sat Nov 15 22:44:45 2003
+++ src/gpscontrol.c	Sun Mar 14 00:15:19 2004
@@ -37,6 +37,9 @@
 #include <unistd.h>
 #include <fcntl.h>
 #include <termios.h>
+#ifdef __FreeBSD__
+#include <string.h>
+#endif
 #include <strings.h>
 #include "gpscontrol.h"
 
