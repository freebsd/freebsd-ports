Part of extended mode being an argument and not a compile time decision.

--- freebsd/tun_dev.c.orig	2016-10-01 21:46:01 UTC
+++ freebsd/tun_dev.c
@@ -35,6 +35,8 @@
 #include "vtun.h"
 #include "lib.h"
 
+extern int extended_mode;
+
 /* 
  * Allocate TUN device, returns opened fd. 
  * Stores dev name in the first arg(must be large enough).
@@ -58,10 +60,8 @@ int tun_open(char *dev)
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
