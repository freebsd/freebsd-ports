--- encodedv/dvconnect.c.orig	Wed Jul  3 14:44:37 2002
+++ encodedv/dvconnect.c	Wed Jul  3 14:51:44 2002
@@ -26,6 +26,7 @@
 
 #include <stdio.h>
 #include <sys/ioctl.h>
+#include <sys/types.h>
 #include <sys/mman.h>
 #include <sys/time.h>
 #include <unistd.h>
