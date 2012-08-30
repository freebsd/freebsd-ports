--- mozilla/ipc/chromium/src/base/message_pump_libevent.cc~
+++ mozilla/ipc/chromium/src/base/message_pump_libevent.cc
@@ -15,7 +15,7 @@
 #include "base/scoped_nsautorelease_pool.h"
 #include "base/scoped_ptr.h"
 #include "base/time.h"
-#include "third_party/libevent/event.h"
+#include "event.h"
 
 // Lifecycle of struct event
 // Libevent uses two main data structures:
