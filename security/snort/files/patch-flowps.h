--- src/preprocessors/flow/portscan/flowps.h.orig	Fri Dec 19 14:37:56 2003
+++ src/preprocessors/flow/portscan/flowps.h	Fri Dec 19 14:39:51 2003
@@ -6,7 +6,12 @@
 #endif
 
 #include <time.h>
-#include <stdint.h>
+
+#if HAVE_STDINT_H
+ #include <stdint.h>
+#else
+ #include <inttypes.h>
+#endif
 
 #include "flow.h"
 #include "unique_tracker.h"
