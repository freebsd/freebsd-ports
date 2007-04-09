--- src/utl/UtlContainer.cpp.orig	Sat Apr  7 17:16:07 2007
+++ src/utl/UtlContainer.cpp	Sat Apr  7 17:16:47 2007
@@ -7,6 +7,8 @@
 //////
 
 // SYSTEM INCLUDES
+#include <stdint.h>
+
 // APPLICATION INCLUDES
 #include "utl/UtlContainer.h"
 #include "utl/UtlLink.h"
@@ -86,7 +88,7 @@
 unsigned UtlContainer::hash() const
 {
    // default implementation
-   return (unsigned) this;
+   return (unsigned) ((uintptr_t)this);
 }
 
 
@@ -109,7 +111,7 @@
  */
 int UtlContainer::compareTo(const UtlContainable* otherObject) const
 {
-   return ((unsigned) this) - ((unsigned) otherObject);
+   return ((unsigned) ((uintptr_t)this)) - ((unsigned) ((uintptr_t)otherObject));
 }
 
 
