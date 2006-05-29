--- lib/memory.c.orig	Thu Mar 30 19:47:38 2006
+++ lib/memory.c	Thu May 11 10:18:36 2006
@@ -21,7 +21,7 @@
  */
 
 #include <zebra.h>
-#include <malloc.h>
+#include <stdlib.h>
 
 #include "log.h"
 #include "memory.h"
