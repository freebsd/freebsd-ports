--- src/freebsd.h.orig 2009-05-03 20:22:29.000000000 +0300
+++ src/freebsd.h 2009-05-03 20:22:11.000000000 +0300
@@ -2,6 +2,7 @@
 #define FREEBSD_H_
 
 #include "common.h"
+#include <sys/param.h>
 #include <sys/mount.h>
 #include <sys/ucred.h>
 #include <fcntl.h>
