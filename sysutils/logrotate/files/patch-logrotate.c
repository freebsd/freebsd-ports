--- logrotate.c.orig	2017-10-12 15:19:41 UTC
+++ logrotate.c
@@ -1,6 +1,6 @@
 #include "queue.h"
 /* alloca() is defined in stdlib.h in NetBSD */
-#ifndef __NetBSD__
+#if !defined(__FreeBSD__) && !defined(__NetBSD__)
 #include <alloca.h>
 #endif
 #include <limits.h>
@@ -29,6 +29,8 @@
 
 #include "log.h"
 #include "logrotate.h"
+
+struct logInfoHead logs;
 
 static void *prev_context;
 #ifdef WITH_SELINUX
