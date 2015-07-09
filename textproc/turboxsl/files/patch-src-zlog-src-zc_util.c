--- src/zlog/src/zc_util.c.orig	2015-07-10 03:36:43.533900000 +0900
+++ src/zlog/src/zc_util.c	2015-07-10 03:36:53.470268000 +0900
@@ -6,6 +6,7 @@
  * Licensed under the LGPL v2.1, see the file COPYING in base directory.
  */
 
+#include <sys/types.h>
 #include <string.h>
 #include <syslog.h>
 #include <stdlib.h>
