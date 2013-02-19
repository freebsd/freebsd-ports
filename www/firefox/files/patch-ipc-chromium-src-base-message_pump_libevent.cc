--- ipc/chromium/src/base/message_pump_libevent.cc~
+++ ipc/chromium/src/base/message_pump_libevent.cc
@@ -16,7 +16,7 @@
 #include "base/scoped_ptr.h"
 #include "base/time.h"
 #include "nsDependentSubstring.h"
-#include "third_party/libevent/event.h"
+#include "event.h"
 
 // Lifecycle of struct event
 // Libevent uses two main data structures:
