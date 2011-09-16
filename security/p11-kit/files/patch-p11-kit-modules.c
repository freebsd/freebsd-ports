--- p11-kit/modules.c.orig	2011-09-15 18:15:24.000000000 -0700
+++ p11-kit/modules.c	2011-09-15 18:16:27.000000000 -0700
@@ -50,11 +50,12 @@
 #include <dirent.h>
 #include <dlfcn.h>
 #include <errno.h>
+#include <limits.h>
 #include <pthread.h>
 #include <stdarg.h>
 #include <stddef.h>
-#include <stdlib.h>
 #include <stdio.h>
+#include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
 
