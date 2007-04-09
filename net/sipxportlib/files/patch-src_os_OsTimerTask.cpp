--- src/os/OsTimerTask.cpp.orig	Sat Apr  7 19:40:53 2007
+++ src/os/OsTimerTask.cpp	Sat Apr  7 19:41:56 2007
@@ -9,6 +9,7 @@
 
 // SYSTEM INCLUDES
 #include <assert.h>
+#include <stdint.h>
 
 // APPLICATION INCLUDES
 #include "os/OsEvent.h"
@@ -377,7 +378,7 @@
    // Call the event routine if we are supposed to.
    if (report)
    {
-      timer->mpNotifier->signal((int) timer);
+      timer->mpNotifier->signal((int) ((uintptr_t)timer));
    }
 }
 
