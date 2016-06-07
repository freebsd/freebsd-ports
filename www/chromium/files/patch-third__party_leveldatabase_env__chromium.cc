--- third_party/leveldatabase/env_chromium.cc.orig	2016-05-11 19:02:34 UTC
+++ third_party/leveldatabase/env_chromium.cc
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
