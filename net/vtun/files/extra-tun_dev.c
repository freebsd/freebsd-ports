--- freebsd/tun_dev.c.orig	Thu Aug 26 16:45:24 2004
+++ freebsd/tun_dev.c	Thu Aug 26 16:45:42 2004
@@ -58,8 +58,8 @@
        }
     }
     if( fd > -1 ){
-       i=0;
-       /* Disable extended modes */
+       i=1;
+       /* Enable extended modes */
        ioctl(fd, TUNSLMODE, &i);	
        ioctl(fd, TUNSIFHEAD, &i);
     }	
