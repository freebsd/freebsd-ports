--- src/process.cc.orig	2024-10-30 15:32:39 UTC
+++ src/process.cc
@@ -16,6 +16,9 @@
  * For more information : contact@centreon.com
  */
 
+#if defined(__FreeBSD__) || defined (__DragonFly__)
+#include <array>
+#endif
 #include <sstream>
 
 #include <fcntl.h>
