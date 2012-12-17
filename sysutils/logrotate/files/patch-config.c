--- config.c.orig	2012-11-09 18:58:51.756188812 +0800
+++ config.c	2012-11-09 19:00:23.064190229 +0800
@@ -1,8 +1,4 @@
 #include <sys/queue.h>
-/* Alloca is defined in stdlib.h in NetBSD */
-#ifndef __NetBSD__
-#include <alloca.h>
-#endif
 #include <limits.h>
 #include <ctype.h>
 #include <dirent.h>
