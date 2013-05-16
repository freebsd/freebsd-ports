--- daemon/object_manager.cc.orig	2013-05-14 11:57:51.191911826 +0000
+++ daemon/object_manager.cc	2013-05-14 12:00:23.328908089 +0000
@@ -60,7 +60,10 @@
 #include "daemon/object_manager.h"
 #include "daemon/replicant_state_machine.h"
 #include "daemon/replicant_state_machine_context.h"
-#if defined __APPLE__
+#if defined __APPLE__ || defined __FreeBSD__
+#ifdef __FreeBSD__
+#include <sys/stat.h>
+#endif
 #include "daemon/memstream.h"
 #endif
 
