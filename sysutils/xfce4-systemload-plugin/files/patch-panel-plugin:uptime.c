--- panel-plugin/uptime.c.orig	Thu Nov 13 20:01:50 2003
+++ panel-plugin/uptime.c	Fri May 20 22:31:11 2005
@@ -81,6 +81,7 @@
 #include <string.h>
 #include <sys/param.h>
 #include <sys/sysctl.h>
+#include <sys/time.h>
 #include <sys/types.h>
 #include <sys/vmmeter.h>
 #include <unistd.h>
@@ -94,7 +95,7 @@
    int mib[2] = {CTL_KERN, KERN_BOOTTIME};
    struct timeval boottime;
    time_t now;
-   int size = sizeof(boottime);
+   size_t size = sizeof(boottime);
    gulong uptime;
  
    if((sysctl(mib, 2, &boottime, &size, NULL, 0) != -1)
