--- third_party/leveldatabase/env_chromium.cc.orig	2016-10-06 04:02:41.000000000 +0300
+++ third_party/leveldatabase/env_chromium.cc	2016-10-13 08:33:43.174604000 +0300
@@ -23,7 +23,11 @@
 #include "base/trace_event/trace_event.h"
 #include "third_party/leveldatabase/chromium_logger.h"
 #include "third_party/leveldatabase/src/include/leveldb/options.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 
 using base::FilePath;
 using leveldb::FileLock;
