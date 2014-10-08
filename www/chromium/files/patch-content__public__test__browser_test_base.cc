--- content/public/test/browser_test_base.cc.orig	2014-10-02 17:39:47 UTC
+++ content/public/test/browser_test_base.cc
@@ -4,6 +4,10 @@
 
 #include "content/public/test/browser_test_base.h"
 
+#if defined(OS_FREEBSD)
+#include <sys/signal.h>
+#endif
+
 #include "base/bind.h"
 #include "base/command_line.h"
 #include "base/debug/stack_trace.h"
