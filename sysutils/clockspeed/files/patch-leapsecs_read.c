--- leapsecs_read.c.orig	Thu May 24 20:07:04 2001
+++ leapsecs_read.c	Thu May 24 20:12:33 2001
@@ -18,7 +18,7 @@
   int i;
   struct tai u;
 
-  fd = open("/etc/leapsecs.dat",O_RDONLY | O_NDELAY);
+  fd = open("%%PREFIX%%/etc/clockspeed/leapsecs.dat",O_RDONLY | O_NDELAY);
   if (fd == -1) {
     if (errno != ENOENT) return -1;
     if (leapsecs) free(leapsecs);
