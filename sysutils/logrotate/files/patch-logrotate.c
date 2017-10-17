--- logrotate.c.orig	2017-10-12 15:19:41.000000000 +0000
+++ logrotate.c	2017-10-14 22:00:57.613844000 +0000
@@ -1,6 +1,6 @@
 #include "queue.h"
 /* alloca() is defined in stdlib.h in NetBSD */
-#ifndef __NetBSD__
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 #include <alloca.h>
 #endif
 #include <limits.h>
