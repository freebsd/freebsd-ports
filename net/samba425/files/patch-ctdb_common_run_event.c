--- ctdb/common/run_event.c.orig	2026-01-20 22:42:53.866815000 +0700
+++ ctdb/common/run_event.c	2026-08-27 14:33:05.081967000 +0700
@@ -25,7 +25,12 @@
 
 #include <talloc.h>
 #include <tevent.h>
+#include <errno.h>
 
+#ifndef ENODATA
+#define ENODATA ENOATTR
+#endif
+
 #include "lib/util/tevent_unix.h"
 #include "lib/util/debug.h"
 
