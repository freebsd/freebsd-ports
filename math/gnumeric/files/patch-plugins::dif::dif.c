
$FreeBSD$

--- plugins/dif/dif.c	2001/07/09 16:17:34	1.1
+++ plugins/dif/dif.c	2001/07/09 16:17:57
@@ -8,6 +8,7 @@
  *	Based on ff-csv code.
  */
 #include <config.h>
+#include <sys/types.h>
 #include <sys/mman.h>
 #include <unistd.h>
 #include <stdio.h>
