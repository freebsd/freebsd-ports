--- logrotate.c.orig	2015-02-13 06:11:21 UTC
+++ logrotate.c
@@ -1,8 +1,4 @@
 #include "queue.h"
-/* alloca() is defined in stdlib.h in NetBSD */
-#ifndef __NetBSD__
-#include <alloca.h>
-#endif
 #include <limits.h>
 #include <ctype.h>
 #include <dirent.h>
