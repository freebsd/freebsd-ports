--- src/zlog/src/category_table.c.orig	2015-07-10 03:28:51.992237000 +0900
+++ src/zlog/src/category_table.c	2015-07-10 03:29:10.446286000 +0900
@@ -6,6 +6,7 @@
  * Licensed under the LGPL v2.1, see the file COPYING in base directory.
  */
 
+#include <sys/types.h>
 #include <string.h>
 #include <stdlib.h>
 #include <errno.h>
