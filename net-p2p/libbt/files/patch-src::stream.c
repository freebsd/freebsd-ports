--- src/stream.c.old	Thu Feb 26 17:34:48 2004
+++ src/stream.c	Thu Feb 26 17:35:11 2004
@@ -1,4 +1,5 @@
 #include "config.h"
+#include <sys/types.h>
 #include <errno.h>
 #include <string.h>
 #include <stdarg.h>
@@ -14,7 +15,6 @@
 	#include <unistd.h>
     #endif
 #endif
-#include <sys/types.h>
 #include "bterror.h"
 #include "stream.h"
 #undef DEBUG_STREAM
