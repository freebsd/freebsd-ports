--- content/public/test/browser_test_base.cc.orig	2019-07-24 18:58:24 UTC
+++ content/public/test/browser_test_base.cc
@@ -75,6 +75,10 @@
 #include "ui/views/test/event_generator_delegate_mac.h"
 #endif
 
+#if defined(OS_FREEBSD)
+#include <sys/signal.h>
+#endif
+
 #if defined(OS_POSIX)
 #include "base/process/process_handle.h"
 #endif
