--- src/utl/UtlVoidPtr.cpp.orig	Sat Apr  7 16:57:45 2007
+++ src/utl/UtlVoidPtr.cpp	Sat Apr  7 17:00:29 2007
@@ -8,6 +8,7 @@
 
 // SYSTEM INCLUDES
 #include <string.h>
+#include <stdint.h>
 
 // APPLICATION INCLUDES
 #include "utl/UtlInt.h"
@@ -57,7 +58,7 @@
 
 unsigned UtlVoidPtr::hash() const
 {
-    return (unsigned) mpValue ; 
+    return (unsigned) ((uintptr_t)mpValue) ; 
 }
 
 
@@ -75,7 +76,7 @@
    
    if (inVal->isInstanceOf(UtlVoidPtr::TYPE))
    {
-      result = ((unsigned) mpValue) - ((unsigned) ((UtlVoidPtr*) inVal)->mpValue);
+      result = ((unsigned) ((uintptr_t)mpValue)) - ((unsigned) ((uintptr_t)((UtlVoidPtr*) inVal)->mpValue));
    }
    else
    {
