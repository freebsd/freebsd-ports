-- On FreeBSD, the bundled glog Mutex destructor (via pthread_rwlock_destroy)
-- returns EBUSY when rwlocks are still held at process exit, causing abort(9).
-- This build-time code generator has fully completed when main() returns, so
-- it is safe to skip C++ static destructors by calling _exit() directly.
--- paddle/fluid/pybind/generator.cc.orig	2026-06-20 02:42:30 UTC
+++ paddle/fluid/pybind/generator.cc
@@ -13,16 +13,22 @@
 // limitations under the License.
 
 #include <iostream>
+#include <unistd.h>
 #include "paddle/fluid/pybind/eager_generator.h"
 #include "paddle/fluid/pybind/eager_legacy_op_function_generator.h"
 
 int main(int argc, char* argv[]) {
   if (argc == 2) {
     // make eager_legacy_op_function_generator.cc
-    return run_legacy_generator(argc, argv);
+    // Use _exit to skip C++ static destructors.  On FreeBSD the bundled
+    // glog Mutex destructor calls pthread_rwlock_destroy() which returns
+    // EBUSY when a rwlock is still held at exit-time, causing abort(9).
+    // The generation has completed successfully at this point; skipping
+    // the destructors is safe for a build-time code generator tool.
+    _exit(run_legacy_generator(argc, argv));
   } else if (argc == 3) {
     // make eager_generator.cc
-    return run_generator(argc, argv);
+    _exit(run_generator(argc, argv));
   } else {
     std::cerr << "argc must be 2 or 3" << std::endl;
     return -1;
