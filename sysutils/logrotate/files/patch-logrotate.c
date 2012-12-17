--- logrotate.c.orig	2012-11-09 19:00:58.744187984 +0800
+++ logrotate.c	2012-11-09 19:01:05.528189740 +0800
@@ -1,8 +1,4 @@
 #include <sys/queue.h>
-/* alloca() is defined in stdlib.h in NetBSD */
-#ifndef __NetBSD__
-#include <alloca.h>
-#endif
 #include <limits.h>
 #include <ctype.h>
 #include <dirent.h>
