--- leapsecs_read.c.orig
+++ leapsecs_read.c
@@ -2,7 +2,6 @@
 #include <sys/stat.h>
 #include <fcntl.h>
 #include <errno.h>
-extern int errno;
 #include "tai.h"
 #include "leapsecs.h"
 
