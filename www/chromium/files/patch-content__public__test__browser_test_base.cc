--- content/public/test/browser_test_base.cc.orig	2013-01-08 23:22:25.608704051 +0200
+++ content/public/test/browser_test_base.cc	2013-01-08 23:24:45.354245363 +0200
@@ -4,6 +4,10 @@
 
 #include "content/public/test/browser_test_base.h"
 
+#if defined(OS_FREEBSD)
+#include <sys/signal.h>
+#endif
+
 #include "base/bind.h"
 #include "base/command_line.h"
 #include "base/debug/stack_trace.h"
