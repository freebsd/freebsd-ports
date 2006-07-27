--- src/idmef-path.c.orig	Mon Jul  3 05:48:45 2006
+++ src/idmef-path.c	Thu Jul 27 07:17:26 2006
@@ -30,6 +30,7 @@
 #include <sys/types.h>
 #include <stdarg.h>
 #include <limits.h>
+#include <assert.h>
 
 #include "prelude-thread.h"
 #include "prelude-hash.h"
