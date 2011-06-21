--- ipc/chromium/src/base/atomicops_internals_mutex.cc~
+++ ipc/chromium/src/base/atomicops_internals_mutex.cc
@@ -39,6 +39,7 @@
  * ***** END LICENSE BLOCK ***** */
 
 #include "base/atomicops.h"
+#include "base/lock.h"
 
 namespace base {
 namespace subtle {
