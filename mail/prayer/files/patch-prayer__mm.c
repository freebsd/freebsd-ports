--- prayer/mm.c.orig	Sun Sep 30 15:50:26 2007
+++ prayer/mm.c	Sun Sep 30 15:50:30 2007
@@ -31,7 +31,7 @@
 /* Must call mminit before any other fn */
 void mm_init()
 {
-#include "linkage.c"
+#include "linkage.h"
 
     ml_init();
 }
