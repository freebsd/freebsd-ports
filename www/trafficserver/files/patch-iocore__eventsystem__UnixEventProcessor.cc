--- iocore/eventsystem/UnixEventProcessor.cc.orig	2014-07-07 00:33:37.106586000 +0800
+++ iocore/eventsystem/UnixEventProcessor.cc	2014-07-07 00:34:18.143512000 +0800
@@ -24,7 +24,6 @@
 #include "P_EventSystem.h"      /* MAGIC_EDITING_TAG */
 #include <sched.h>
 #if TS_USE_HWLOC
-#include <alloca.h>
 #include <hwloc.h>
 #endif
 #include "ink_defs.h"
