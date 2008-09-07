--- talk/base/stringencode.cc.orig	2008-09-06 23:16:12.000000000 -0300
+++ talk/base/stringencode.cc	2008-09-06 23:25:50.000000000 -0300
@@ -25,11 +25,19 @@
  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  */
 
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+
 #ifdef WIN32
 #include <malloc.h>
 #endif  // WIN32
 #ifdef POSIX
+#ifdef __FreeBSD__
+#include <stdlib.h>
+#else
 #include <alloca.h>
+#endif
 #define _alloca alloca
 #endif  // POSIX
 
