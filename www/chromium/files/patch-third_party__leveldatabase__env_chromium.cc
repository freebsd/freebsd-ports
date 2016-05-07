--- third_party/leveldatabase/env_chromium.cc.orig	2016-03-05 15:11:05.662072033 +0100
+++ third_party/leveldatabase/env_chromium.cc	2016-03-05 15:11:42.630069103 +0100
@@ -21,7 +21,11 @@
 #include "base/threading/thread_restrictions.h"
 #include "base/trace_event/trace_event.h"
 #include "third_party/leveldatabase/chromium_logger.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 
 using base::FilePath;
 using leveldb::FileLock;
