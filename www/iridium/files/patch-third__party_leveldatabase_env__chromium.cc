--- third_party/leveldatabase/env_chromium.cc.orig	2017-04-19 19:06:52 UTC
+++ third_party/leveldatabase/env_chromium.cc
@@ -25,7 +25,11 @@
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
