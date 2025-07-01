--- tensorflow/python/util/function_parameter_canonicalizer.cc.orig	2023-09-12 16:46:28 UTC
+++ tensorflow/python/util/function_parameter_canonicalizer.cc
@@ -16,6 +16,7 @@ limitations under the License.
 #include "tensorflow/python/util/function_parameter_canonicalizer.h"
 
 #include "absl/container/flat_hash_set.h"
+#include "absl/strings/str_cat.h"
 #include "tensorflow/core/platform/logging.h"
 #include "tensorflow/core/platform/macros.h"
 #include "tensorflow/python/lib/core/py_util.h"
