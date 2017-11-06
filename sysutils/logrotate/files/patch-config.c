--- config.c.orig	2017-10-12 15:19:41.000000000 +0000
+++ config.c	2017-10-14 21:59:41.716559000 +0000
@@ -1,6 +1,6 @@
 #include "queue.h"
 /* Alloca is defined in stdlib.h in NetBSD */
-#ifndef __NetBSD__
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 #include <alloca.h>
 #endif
 #include <limits.h>
