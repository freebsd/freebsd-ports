--- src/preprocessors/flow/flow_stat.h.orig	Fri Dec 19 14:37:49 2003
+++ src/preprocessors/flow/flow_stat.h	Fri Dec 19 14:39:27 2003
@@ -2,8 +2,13 @@
 #define _FLOW_STAT_H
 
 #include <stdio.h>
-#include <stdint.h>
 #include <time.h>
+
+#if HAVE_STDINT_H
+ #include <stdint.h>
+#else
+ #include <inttypes.h>
+#endif
 
 #include "flow.h"
 
