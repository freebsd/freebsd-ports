--- quanta/plugins/php4dbg/listener.cpp.orig	Thu Jan 24 17:27:25 2002
+++ quanta/plugins/php4dbg/listener.cpp	Thu Jan 24 17:27:41 2002
@@ -1,4 +1,4 @@
-
+#include <sys/types.h>
 #include "listener.h"
 
 #include <stdarg.h>
