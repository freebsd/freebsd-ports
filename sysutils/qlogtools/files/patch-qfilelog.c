--- qfilelog.c.orig
+++ qfilelog.c
@@ -1,10 +1,9 @@
+#include <errno.h>
 #include <fcntl.h>
 #include <signal.h>
 #include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
-
-extern int errno;
 
 #define PAUSE sleep(60)
 
