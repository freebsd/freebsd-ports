--- tuntap.c	Sat Jan 29 15:02:08 2005
+++ tuntap.c	Sun Jan 30 00:27:23 2005
@@ -11,8 +11,16 @@
 #include <unistd.h>
 #include <syslog.h>
 #include <sys/ioctl.h>
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#include <sys/socket.h>
+#endif
 #include <net/if.h>
+#ifdef __FreeBSD__
+#include <net/if_tun.h>
+#else
 #include <linux/if_tun.h>
+#endif
 #include "port.h"
 #include "switch.h"
 
@@ -28,13 +36,16 @@
 
 int open_tap(char *dev)
 {
+#ifndef __FreeBSD__
   struct ifreq ifr;
+#endif
   int fd;
 
-  if((fd = open("/dev/net/tun", O_RDWR)) < 0){
-    printlog(LOG_ERR,"Failed to open /dev/net/tun %s",strerror(errno));
+  if((fd = open(dev, O_RDWR)) < 0){
+    printlog(LOG_ERR,"Failed to open %s %s", dev, strerror(errno));
     return(-1);
   }
+#ifndef __FreeBSD__
   memset(&ifr, 0, sizeof(ifr));
   ifr.ifr_flags = IFF_TAP | IFF_NO_PI;
   strncpy(ifr.ifr_name, dev, sizeof(ifr.ifr_name) - 1);
@@ -43,5 +54,6 @@
     close(fd);
     return(-1);
   }
+#endif
   return(fd);
 }
