--- src/3rdparty/chromium/third_party/leveldatabase/env_chromium.cc.orig	2017-01-26 00:49:30 UTC
+++ src/3rdparty/chromium/third_party/leveldatabase/env_chromium.cc
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
