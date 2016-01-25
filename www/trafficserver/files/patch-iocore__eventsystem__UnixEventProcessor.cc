--- iocore/eventsystem/UnixEventProcessor.cc.orig	2015-09-08 17:43:45 UTC
+++ iocore/eventsystem/UnixEventProcessor.cc
@@ -24,7 +24,6 @@
 #include "P_EventSystem.h" /* MAGIC_EDITING_TAG */
 #include <sched.h>
 #if TS_USE_HWLOC
-#include <alloca.h>
 #include <hwloc.h>
 #endif
 #include "ts/ink_defs.h"
