--- src/zlog/src/event.c.orig	2015-07-02 18:01:10 UTC
+++ src/zlog/src/event.c
@@ -7,6 +7,7 @@
  */
 
 #include "fmacros.h"
+#include <sys/types.h>
 #include <string.h>
 #include <stdarg.h>
 #include <stdlib.h>
