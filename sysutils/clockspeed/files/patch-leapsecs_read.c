--- leapsecs_read.c.orig
+++ leapsecs_read.c
@@ -2,7 +2,6 @@
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <errno.h>
-extern int errno;
 #include "tai.h"
 #include "leapsecs.h"
 
@@ -18,7 +17,7 @@
   int i;
   struct tai u;
 
-  fd = open("/etc/leapsecs.dat",O_RDONLY | O_NDELAY);
+  fd = open("%%PREFIX%%/etc/clockspeed/leapsecs.dat",O_RDONLY | O_NDELAY);
   if (fd == -1) {
     if (errno != ENOENT) return -1;
     if (leapsecs) free(leapsecs);
