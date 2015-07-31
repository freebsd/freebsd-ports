--- src/zlog/src/record_table.c.orig	2015-07-02 18:01:10 UTC
+++ src/zlog/src/record_table.c
@@ -6,6 +6,7 @@
  * Licensed under the LGPL v2.1, see the file COPYING in base directory.
  */
 
+#include <sys/types.h>
 #include <string.h>
 #include <stdlib.h>
 #include <errno.h>
