--- src/process_manager.cc.orig	2021-04-01 07:25:04 UTC
+++ src/process_manager.cc
@@ -19,6 +19,10 @@
 #include "com/centreon/process_manager.hh"
 #include <sys/wait.h>
 #include <unistd.h>
+#if defined(__FreeBSD__) || defined (__DragonFly__)
+#include <signal.h>
+#include <array>
+#endif
 #include <algorithm>
 #include <cassert>
 #include <cerrno>
