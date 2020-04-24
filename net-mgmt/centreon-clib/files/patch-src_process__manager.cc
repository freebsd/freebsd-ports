--- src/process_manager.cc.orig	2020-04-24 11:44:54 UTC
+++ src/process_manager.cc
@@ -24,6 +24,9 @@
 #include <sys/types.h>
 #include <sys/wait.h>
 #include <unistd.h>
+#if defined(__FreeBSD__) || defined (__DragonFly__)
+#include <signal.h>
+#endif
 #include "com/centreon/exceptions/basic.hh"
 #include "com/centreon/logging/logger.hh"
 #include "com/centreon/process.hh"
