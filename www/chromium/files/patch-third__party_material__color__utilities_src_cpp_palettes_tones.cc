--- third_party/material_color_utilities/src/cpp/palettes/tones.cc.orig	2023-09-13 12:11:42 UTC
+++ third_party/material_color_utilities/src/cpp/palettes/tones.cc
@@ -14,6 +14,8 @@
  * limitations under the License.
  */
 
+#include <cmath>
+
 #include "cpp/palettes/tones.h"
 
 #include "cpp/cam/cam.h"
