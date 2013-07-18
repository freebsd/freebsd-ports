--- third_party/libjingle/source/talk/base/linux.cc.orig	2013-07-15 17:38:04.000000000 +0300
+++ third_party/libjingle/source/talk/base/linux.cc	2013-07-15 17:39:04.000000000 +0300
@@ -25,7 +25,7 @@
  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  */
 
-#if defined(LINUX) || defined(ANDROID)
+#if defined(LINUX) || defined(ANDROID) || defined(BSD)
 #include "talk/base/linux.h"
 
 #include <ctype.h>
@@ -279,4 +279,4 @@
 
 }  // namespace talk_base
 
-#endif  // defined(LINUX) || defined(ANDROID)
+#endif  // defined(LINUX) || defined(ANDROID) || defined(BSD)
