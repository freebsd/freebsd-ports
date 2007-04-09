--- src/os/OsMsg.cpp.orig	Sat Apr  7 18:07:29 2007
+++ src/os/OsMsg.cpp	Sat Apr  7 18:08:23 2007
@@ -8,6 +8,7 @@
 
 // SYSTEM INCLUDES
 #include <assert.h>
+#include <stdint.h>
 
 // APPLICATION INCLUDES
 #include "os/OsMsg.h"
@@ -150,7 +151,7 @@
 //! Implements the interface for a UtlContainable
 unsigned OsMsg::hash() const
 {
-   return (unsigned) this;
+   return (unsigned) ((uintptr_t)this);
 }
 
 UtlContainableType OsMsg::getContainableType() const
@@ -160,7 +161,7 @@
 
 int OsMsg::compareTo(UtlContainable const* other) const
 {
-   return ((unsigned) this) - ((unsigned) other);
+   return ((unsigned) ((uintptr_t)this)) - ((unsigned) ((uintptr_t)other));
 }
 
 
