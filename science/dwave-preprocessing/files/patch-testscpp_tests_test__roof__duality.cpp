--- testscpp/tests/test_roof_duality.cpp.orig	2022-12-19 19:58:20 UTC
+++ testscpp/tests/test_roof_duality.cpp
@@ -12,7 +12,7 @@
 // See the License for the specific language governing permissions and
 // limitations under the License.
 
-#include "catch2/catch.hpp"
+#include <catch2/catch.hpp>
 #include <dimod/quadratic_model.h>
 
 #include "dwave-preprocessing/fix_variables.hpp"
