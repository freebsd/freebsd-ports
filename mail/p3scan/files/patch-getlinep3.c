--- getlinep3.c.orig	Mon May  1 00:39:10 2006
+++ getlinep3.c	Mon May  1 00:39:28 2006
@@ -37,7 +37,7 @@
 #include <stdio.h>
 #include <unistd.h>
 #include <string.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include <stdarg.h>
 #include <fcntl.h>
 #include <sys/time.h>
