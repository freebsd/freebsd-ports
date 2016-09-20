--- freebsd/tun_dev.c.orig	2008-01-07 14:36:10.000000000 -0800
+++ freebsd/tun_dev.c	2016-09-19 20:06:49.919502000 -0700
@@ -35,6 +35,8 @@
 #include "vtun.h"
 #include "lib.h"
 
+extern int extended_mode;
+
 /* 
  * Allocate TUN device, returns opened fd. 
  * Stores dev name in the first arg(must be large enough).
@@ -58,10 +60,8 @@
        }
     }
     if( fd > -1 ){
-       i=0;
-       /* Disable extended modes */
-       ioctl(fd, TUNSLMODE, &i);	
-       ioctl(fd, TUNSIFHEAD, &i);
+       ioctl(fd, TUNSLMODE, &extended_mode);	
+       ioctl(fd, TUNSIFHEAD, &extended_mode);
     }	
     return fd;
 }
