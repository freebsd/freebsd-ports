--- ctdb/event/event_context.c.orig	2026-08-27 15:48:40.460901000 +0700
+++ ctdb/event/event_context.c	2026-08-27 15:49:15.074753000 +0700
@@ -22,7 +22,12 @@
 
 #include <talloc.h>
 #include <tevent.h>
+#include <errno.h>
 
+#ifndef ENODATA
+#define ENODATA ENOATTR
+#endif
+
 #include "lib/util/debug.h"
 #include "lib/util/dlinklist.h"
 
