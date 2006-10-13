--- ./src/search.c.orig	Fri Oct 13 12:20:23 2006
+++ ./src/search.c	Fri Oct 13 12:20:38 2006
@@ -12,6 +12,7 @@
 #include <stdlib.h>
 #include <stdarg.h>
 #include <errno.h>
+#include <pthread.h>
 
 #include "interface.h"
 #include "support.h"
