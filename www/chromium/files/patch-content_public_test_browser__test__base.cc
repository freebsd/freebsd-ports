--- content/public/test/browser_test_base.cc.orig	2021-01-18 21:28:57 UTC
+++ content/public/test/browser_test_base.cc
@@ -106,6 +106,10 @@
 #include "ui/views/test/event_generator_delegate_mac.h"
 #endif
 
+#if defined(OS_FREEBSD)
+#include <sys/signal.h>
+#endif
+
 #if defined(OS_POSIX)
 #include "base/process/process_handle.h"
 #endif
