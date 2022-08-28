--- testscpp/tests/test_roof_duality.cpp.orig	2022-08-28 01:26:12 UTC
+++ testscpp/tests/test_roof_duality.cpp
@@ -12,7 +12,7 @@
 // See the License for the specific language governing permissions and
 // limitations under the License.
 
-#include "../Catch2/single_include/catch2/catch.hpp"
+#include <catch2/catch.hpp>
 #include <dimod/quadratic_model.h>
 
 #include "dwave-preprocessing/fix_variables.hpp"
