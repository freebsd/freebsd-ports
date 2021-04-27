--- content/public/test/browser_test_base.cc.orig	2021-04-14 18:41:03 UTC
+++ content/public/test/browser_test_base.cc
@@ -109,6 +109,10 @@
 #include "ui/views/test/event_generator_delegate_mac.h"
 #endif
 
+#if defined(OS_FREEBSD)
+#include <sys/signal.h>
+#endif
+
 #if defined(OS_POSIX)
 #include "base/process/process_handle.h"
 #endif
