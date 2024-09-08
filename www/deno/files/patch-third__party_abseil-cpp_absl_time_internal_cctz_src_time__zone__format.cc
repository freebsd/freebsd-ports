Why is it needed?
error: use of undeclared identifier 'FP_NAN'

--- cargo-crates/v8-0.105.0/third_party/abseil-cpp/absl/time/internal/cctz/src/time_zone_format.cc.orig	2023-08-22 14:51:38 UTC
+++ cargo-crates/v8-0.105.0/third_party/abseil-cpp/absl/time/internal/cctz/src/time_zone_format.cc
@@ -12,6 +12,8 @@
 //   See the License for the specific language governing permissions and
 //   limitations under the License.
 
+#include <math.h>
+
 #if !defined(HAS_STRPTIME)
 #if !defined(_MSC_VER) && !defined(__MINGW32__) && !defined(__VXWORKS__)
 #define HAS_STRPTIME 1  // Assume everyone else has strptime().
