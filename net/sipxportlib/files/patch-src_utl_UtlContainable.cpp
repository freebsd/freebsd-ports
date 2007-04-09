--- src/utl/UtlContainable.cpp.orig	Sat Apr  7 17:08:53 2007
+++ src/utl/UtlContainable.cpp	Sat Apr  7 17:09:20 2007
@@ -8,6 +8,7 @@
 
 // SYSTEM INCLUDES
 #include <string.h>
+#include <stdint.h>
 
 // APPLICATION INCLUDES
 #include "utl/UtlContainable.h"
@@ -60,7 +61,7 @@
 /// Provides a hash function that uses the object pointer as the hash value.
 unsigned UtlContainable::directHash() const
 {
-   return (unsigned) this;
+   return (unsigned) ((uintptr_t)this);
 }
 
 /// Provides a hash function appropriate for null-terminated string values.
