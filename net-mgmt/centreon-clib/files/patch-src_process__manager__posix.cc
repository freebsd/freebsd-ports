--- src/process_manager_posix.cc.orig	2019-10-25 18:23:17 UTC
+++ src/process_manager_posix.cc
@@ -22,6 +22,9 @@
 #include <sys/types.h>
 #include <sys/wait.h>
 #include <unistd.h>
+#if defined(__FreeBSD__) || defined (__DragonFly__)
+#include <signal.h>
+#endif
 #include "com/centreon/concurrency/locker.hh"
 #include "com/centreon/exceptions/basic.hh"
 #include "com/centreon/logging/logger.hh"
