--- tensorflow/stream_executor/stream_executor_pimpl.h.orig	2021-07-07 09:04:03 UTC
+++ tensorflow/stream_executor/stream_executor_pimpl.h
@@ -25,6 +25,7 @@ limitations under the License.
 #include "absl/base/macros.h"
 #include "absl/synchronization/mutex.h"
 #include "absl/types/optional.h"
+#include "absl/memory/memory.h"
 #include "tensorflow/stream_executor/device_memory_allocator.h"
 #include "tensorflow/stream_executor/lib/status.h"
 #include "tensorflow/stream_executor/lib/statusor.h"
