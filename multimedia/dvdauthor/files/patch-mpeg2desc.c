--- src/mpeg2desc.c.orig        Sat Oct  4 02:54:11 2003
+++ src/mpeg2desc.c     Thu Oct  9 01:29:57 2003
@@ -25,6 +25,8 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <sys/types.h>
+#include <sys/time.h>
 #include <unistd.h>
 
 #include <netinet/in.h>
