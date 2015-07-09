--- src/zlog/src/category.c.orig	2015-07-10 03:27:30.714218000 +0900
+++ src/zlog/src/category.c	2015-07-10 03:28:10.280729000 +0900
@@ -6,6 +6,7 @@
  * Licensed under the LGPL v2.1, see the file COPYING in base directory.
  */
 #include "fmacros.h"
+#include <sys/types.h>
 #include <string.h>
 #include <stdlib.h>
 #include <errno.h>
