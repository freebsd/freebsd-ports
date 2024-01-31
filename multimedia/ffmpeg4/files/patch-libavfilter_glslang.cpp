--- libavfilter/glslang.cpp.orig	2023-04-12 18:01:50 UTC
+++ libavfilter/glslang.cpp
@@ -16,6 +16,7 @@
  * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
  */
 
+#include <cassert>
 #include <pthread.h>
 
 extern "C" {
