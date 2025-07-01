--- tensorflow/python/framework/python_api_dispatcher_wrapper.cc.orig	2023-09-12 16:46:28 UTC
+++ tensorflow/python/framework/python_api_dispatcher_wrapper.cc
@@ -14,6 +14,7 @@ limitations under the License.
 ==============================================================================*/
 // Python bindings for tensorflow/python/framework/python_api_dispatcher.h.
 
+#include "absl/strings/str_cat.h"
 #include "pybind11/pybind11.h"  // from @pybind11
 #include "pybind11/pytypes.h"  // from @pybind11
 #include "pybind11/stl.h"  // from @pybind11
