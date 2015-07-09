--- src/zlog/src/event.c.orig	2015-07-10 03:29:45.286866000 +0900
+++ src/zlog/src/event.c	2015-07-10 03:29:59.614232000 +0900
@@ -7,6 +7,7 @@
  */
 
 #include "fmacros.h"
+#include <sys/types.h>
 #include <string.h>
 #include <stdarg.h>
 #include <stdlib.h>
