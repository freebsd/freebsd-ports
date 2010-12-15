--- ParMGridGen/ParLib/parmgridgen.h.orig	2010-02-24 15:21:58.000000000 +0600
+++ ParMGridGen/ParLib/parmgridgen.h	2010-02-24 15:22:03.000000000 +0600
@@ -21,7 +21,7 @@
 #ifdef DMALLOC
 #include <dmalloc.h>
 #else
-#include <malloc.h>
+#include <stdlib.h>
 #endif
 
 #include "IMlib.h"
