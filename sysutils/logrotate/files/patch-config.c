--- config.c.orig	2017-10-12 15:19:41 UTC
+++ config.c
@@ -1,6 +1,6 @@
 #include "queue.h"
 /* Alloca is defined in stdlib.h in NetBSD */
-#ifndef __NetBSD__
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 #include <alloca.h>
 #endif
 #include <limits.h>
@@ -27,6 +27,8 @@
 
 #include "log.h"
 #include "logrotate.h"
+
+extern struct logInfoHead logs;
 
 #if !defined(GLOB_ABORTED) && defined(GLOB_ABEND)
 #define GLOB_ABORTED GLOB_ABEND
