--- ./third_party/libjingle/source/talk/base/linux.cc.orig	2014-04-30 22:44:03.000000000 +0200
+++ ./third_party/libjingle/source/talk/base/linux.cc	2014-05-04 14:38:48.000000000 +0200
@@ -25,7 +25,7 @@
  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  */
 
-#if defined(LINUX) || defined(ANDROID)
+#if defined(LINUX) || defined(ANDROID) || defined(BSD)
 #include "talk/base/linux.h"
 
 #include <ctype.h>
@@ -362,4 +362,4 @@
 
 }  // namespace talk_base
 
-#endif  // defined(LINUX) || defined(ANDROID)
+#endif  // defined(LINUX) || defined(ANDROID) || defined(BSD)
