--- MGridGen/Lib/mgridgen.h.orig	2010-02-24 15:30:01.000000000 +0600
+++ MGridGen/Lib/mgridgen.h	2010-02-24 15:30:09.000000000 +0600
@@ -26,7 +26,7 @@
 #ifdef DMALLOC
 #include <dmalloc.h>
 #else
-#include <malloc.h>
+#include <stdlib.h>
 #endif
 
 #include "defs.h"
