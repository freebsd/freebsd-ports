--- src/os/OsTimer.cpp.orig	Sat Apr  7 19:28:31 2007
+++ src/os/OsTimer.cpp	Sat Apr  7 19:29:10 2007
@@ -9,6 +9,7 @@
 
 // SYSTEM INCLUDES
 #include <assert.h>
+#include <stdint.h>
 
 // APPLICATION INCLUDES
 #include "os/OsTimer.h"
@@ -256,7 +257,7 @@
 
 unsigned OsTimer::hash() const
 {
-    return (unsigned) this;
+    return (unsigned) ((uintptr_t)this);
 }
 
 
@@ -280,7 +281,7 @@
 
    if (inVal->isInstanceOf(OsTimer::TYPE))
    {
-      result = ((unsigned) this) - ((unsigned) inVal);
+      result = ((unsigned) ((uintptr_t)this)) - ((unsigned) ((uintptr_t)inVal));
    }
    else
    {
