--- panel-plugin/uptime.c.orig	Fri Nov 21 16:21:22 2003
+++ panel-plugin/uptime.c	Fri Nov 21 16:21:36 2003
@@ -81,6 +81,7 @@
 #include <string.h>
 #include <sys/param.h>
 #include <sys/sysctl.h>
+#include <sys/time.h>
 #include <sys/types.h>
 #include <sys/vmmeter.h>
 #include <unistd.h>
