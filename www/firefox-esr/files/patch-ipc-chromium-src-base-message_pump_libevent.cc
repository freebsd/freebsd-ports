--- ipc/chromium/src/base/message_pump_libevent.cc~
+++ ipc/chromium/src/base/message_pump_libevent.cc
@@ -6,6 +6,7 @@
 
 #include <errno.h>
 #include <fcntl.h>
+#include <unistd.h>
 
 #include "eintr_wrapper.h"
 #include "base/logging.h"
@@ -15,7 +15,7 @@
 #include "base/scoped_nsautorelease_pool.h"
 #include "base/scoped_ptr.h"
 #include "base/time.h"
-#include "third_party/libevent/event.h"
+#include "event.h"
 
 // Lifecycle of struct event
 // Libevent uses two main data structures:
