--- src/zlog/src/record_table.c.orig	2015-07-10 03:30:42.116741000 +0900
+++ src/zlog/src/record_table.c	2015-07-10 03:30:54.707463000 +0900
@@ -6,6 +6,7 @@
  * Licensed under the LGPL v2.1, see the file COPYING in base directory.
  */
 
+#include <sys/types.h>
 #include <string.h>
 #include <stdlib.h>
 #include <errno.h>
