--- src/os/OsMsgQ.cpp.orig	Sat Apr  7 18:13:52 2007
+++ src/os/OsMsgQ.cpp	Sat Apr  7 18:14:22 2007
@@ -11,6 +11,7 @@
 #ifdef __pingtel_on_posix__
 #  include <pthread.h>
 #endif
+#include <stdint.h>
 
 #include "utl/UtlRscTrace.h"
 
@@ -41,7 +42,7 @@
    mName(name)
 {
    if (mName != "")
-      OsUtil::insertKeyValue(MSGQ_PREFIX, mName, (int) this);
+      OsUtil::insertKeyValue(MSGQ_PREFIX, mName, (int) ((uintptr_t)this));
 }
 
 // Destructor
