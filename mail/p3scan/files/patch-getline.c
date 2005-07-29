--- getline.c.orig     Tue Jul 26 13:29:05 2005
+++ getline.c  Tue Jul 26 11:10:51 2005
@@ -33,11 +33,11 @@
 #include <stdio.h>
 #include <unistd.h>
 #include <string.h>
-#include <malloc.h>
 #include <stdarg.h>
 #include <fcntl.h>
 #include <sys/time.h>
 #include <errno.h>
+#include <stdlib.h>
 
 #include "getline.h"
 
