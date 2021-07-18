--- content/public/test/browser_test_base.cc.orig	2021-05-12 22:05:53 UTC
+++ content/public/test/browser_test_base.cc
@@ -110,6 +110,10 @@
 #include "ui/views/test/event_generator_delegate_mac.h"
 #endif
 
+#if defined(OS_FREEBSD)
+#include <sys/signal.h>
+#endif
+
 #if defined(OS_POSIX)
 #include "base/process/process_handle.h"
 #endif
