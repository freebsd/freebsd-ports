--- ctdb/event/event_tool.c.orig	2026-08-27 15:48:47.912371000 +0700
+++ ctdb/event/event_tool.c	2026-08-27 15:49:35.552239000 +0700
@@ -24,7 +24,12 @@
 #include <popt.h>
 #include <talloc.h>
 #include <tevent.h>
+#include <errno.h>
 
+#ifndef ENODATA
+#define ENODATA ENOATTR
+#endif
+
 #include "lib/util/debug.h"
 
 #include "common/cmdline.h"
