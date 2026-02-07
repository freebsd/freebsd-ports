--- ParMGridGen/IMParMetis-2.0/ParMETISLib/parmetis.h.orig	2010-02-24 15:21:20.000000000 +0600
+++ ParMGridGen/IMParMetis-2.0/ParMETISLib/parmetis.h	2010-02-24 15:21:40.000000000 +0600
@@ -21,7 +21,7 @@
 #ifdef DMALLOC
 #include <dmalloc.h>
 #else
-#include <malloc.h>
+#include <stdlib.h>
 #endif
 
 #include "rename.h"
