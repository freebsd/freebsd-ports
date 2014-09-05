--- nepenthes-core/src/DownloadBuffer.cpp.orig
+++ nepenthes-core/src/DownloadBuffer.cpp
@@ -26,8 +26,9 @@
  *******************************************************************************/
 
 
-#include <stdlib.h>
-#include <errno.h>
+#include <cstdlib>
+#include <cstring>
+#include <cerrno>
 
 #include "DownloadBuffer.hpp"
 #include "Nepenthes.hpp"
