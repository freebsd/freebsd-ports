--- content/public/test/browser_test_base.cc.orig	2019-04-30 22:22:47 UTC
+++ content/public/test/browser_test_base.cc
@@ -63,6 +63,10 @@
 #include "ui/views/test/event_generator_delegate_mac.h"
 #endif
 
+#if defined(OS_FREEBSD)
+#include <sys/signal.h>
+#endif
+
 #if defined(OS_POSIX)
 #include "base/process/process_handle.h"
 #endif
