--- log.c.orig	Tue Feb 22 22:06:18 2005
+++ log.c	Tue Mar  8 01:13:01 2005
@@ -23,6 +23,8 @@
  *
  */
 
+#include <sys/time.h>
+#include <inttypes.h>
 #include <sys/resource.h>
 #include <time.h>
 #include "include/conf.h"
