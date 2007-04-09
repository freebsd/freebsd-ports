--- src/os/OsTask.cpp.orig	Sat Apr  7 19:13:07 2007
+++ src/os/OsTask.cpp	Sat Apr  7 19:19:35 2007
@@ -15,6 +15,7 @@
 
 #include <stdio.h>
 #include <stdarg.h>
+#include <stdint.h>
 
 // APPLICATION INCLUDES
 #include "os/OsExcept.h"
@@ -168,7 +169,7 @@
     mName.append(nameBuffer);
 
    if (mName != "")
-      OsUtil::insertKeyValue(TASK_PREFIX, mName, (int) this);
+      OsUtil::insertKeyValue(TASK_PREFIX, mName, (int) ((uintptr_t)this));
 }
 
 // Destructor
