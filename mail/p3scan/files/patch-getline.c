--- getline.c.orig	Tue Feb 17 21:58:12 2004
+++ getline.c	Tue Feb 17 21:58:17 2004
@@ -30,7 +30,7 @@
 #include <stdio.h>
 #include <unistd.h>
 #include <string.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include <stdarg.h>
 #include <fcntl.h>
 #include <sys/time.h>
