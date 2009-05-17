--- encodedv/dvavi.c.orig	Wed Jan 14 04:29:26 2004
+++ encodedv/dvavi.c	Tue Jul 20 21:07:08 2004
@@ -31,6 +31,7 @@
 
 #include <stdio.h>
 #include <sys/ioctl.h>
+#include <sys/types.h>
 #include <sys/mman.h>
 #include <unistd.h>
 #include <fcntl.h>
