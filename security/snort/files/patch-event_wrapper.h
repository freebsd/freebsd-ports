--- src/event_wrapper.h.orig	Fri Dec 19 14:37:32 2003
+++ src/event_wrapper.h	Fri Dec 19 14:38:49 2003
@@ -1,7 +1,11 @@
 #ifndef _EVENT_WRAPPER_H
 #define _EVENT_WRAPPER_H
 
-#include <stdint.h>
+#if HAVE_STDINT_H
+ #include <stdint.h>
+#else
+ #include <inttypes.h>
+#endif
 
 #include "log.h"
 #include "detect.h"
