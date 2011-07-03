--- ./panel-plugin/uptime.c.orig	2010-12-09 19:04:10.000000000 +0300
+++ ./panel-plugin/uptime.c	2011-07-03 15:39:52.391879944 +0400
@@ -93,7 +93,7 @@
    int mib[2] = {CTL_KERN, KERN_BOOTTIME};
    struct timeval boottime;
    time_t now;
-   int size = sizeof(boottime);
+   size_t size = sizeof(boottime);
    gulong uptime;
  
    if((sysctl(mib, 2, &boottime, &size, NULL, 0) != -1)
