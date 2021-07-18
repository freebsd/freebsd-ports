--- src/process.cc.orig	2021-05-04 21:18:25 UTC
+++ src/process.cc
@@ -16,6 +16,9 @@
 ** For more information : contact@centreon.com
 */
 
+#if defined(__FreeBSD__) || defined (__DragonFly__)
+#include <array>
+#endif
 #include <sstream>
 
 #include <fcntl.h>
