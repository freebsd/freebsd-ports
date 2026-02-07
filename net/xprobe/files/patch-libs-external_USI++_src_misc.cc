--- libs-external/USI++/src/misc.cc.orig	2005-07-27 08:38:15 UTC
+++ libs-external/USI++/src/misc.cc
@@ -1,6 +1,7 @@
 #include "usi++/usi++"
 #include "usi++/usi-structs.h"
 #include <string.h>
+#include <cstdlib>
 #include <unistd.h>
 #include <sys/ioctl.h>
 #include <errno.h>
@@ -17,9 +18,9 @@ unsigned short
 in_cksum (unsigned short *ptr, int nbytes, bool may_pad)
 {
 
-  register long sum;		/* assumes long == 32 bits */
+  long sum;		/* assumes long == 32 bits */
   u_short oddbyte;
-  register u_short answer;	/* assumes u_short == 16 bits */
+  u_short answer;	/* assumes u_short == 16 bits */
 
 
   /* For psuedo-headers: odd len's require
