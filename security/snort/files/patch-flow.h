--- src/preprocessors/flow/flow.h.orig	Fri Dec 19 14:43:23 2003
+++ src/preprocessors/flow/flow.h	Fri Dec 19 14:43:48 2003
@@ -1,7 +1,11 @@
 #ifndef _FLOW_H
 #define _FLOW_H
 
-#include <stdint.h>
+#if HAVE_STDINT_H
+ #include <stdint.h>
+#else
+ #include <inttypes.h>
+#endif
 
 #include "flow_error.h"
 #include "util_math.h"
