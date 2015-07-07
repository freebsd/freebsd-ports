--- osquery/core/init.cpp.orig	2015-07-03 22:32:52 UTC
+++ osquery/core/init.cpp
@@ -31,6 +31,10 @@
 #include "osquery/core/watcher.h"
 #include "osquery/database/db_handle.h"
 
+#ifdef __FreeBSD__
+#include <sys/resource.h>
+#endif
+
 #ifdef __linux__
 #include <sys/resource.h>
 #include <sys/syscall.h>
@@ -238,7 +242,7 @@ void Initializer::initDaemon() {
 #ifdef __linux__
     // Using: ioprio_set(IOPRIO_WHO_PGRP, 0, IOPRIO_CLASS_IDLE);
     syscall(SYS_ioprio_set, IOPRIO_WHO_PGRP, 0, IOPRIO_CLASS_IDLE);
-#elif defined(__APPLE__) || defined(__FreeBSD__)
+#elif defined(__APPLE__)
     setiopolicy_np(IOPOL_TYPE_DISK, IOPOL_SCOPE_PROCESS, IOPOL_THROTTLE);
 #endif
   }
