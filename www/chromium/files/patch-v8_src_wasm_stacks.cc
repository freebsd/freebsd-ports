--- v8/src/wasm/stacks.cc.orig	2026-09-25 15:26:43 UTC
+++ v8/src/wasm/stacks.cc
@@ -4,6 +4,10 @@
 
 #include "src/wasm/stacks.h"
 
+#if V8_OS_OPENBSD
+#include <sys/mman.h>
+#endif
+
 #include "src/base/platform/platform.h"
 #include "src/execution/frames.h"
 #include "src/execution/simulator.h"
@@ -137,6 +141,13 @@ StackMemory::StackSegment::StackSegment(size_t pages) 
                                 "StackMemory::StackSegment::StackSegment");
   }
   limit_ += page_size;
+#if V8_OS_OPENBSD
+  if (mmap(limit_, size_, PROT_READ | PROT_WRITE,
+           MAP_FIXED | MAP_STACK | MAP_ANON | MAP_PRIVATE, -1, 0) == MAP_FAILED) {
+    V8::FatalProcessOutOfMemory(nullptr,
+                              "StackMemory::StackSegment::StackSegment");
+  }
+#endif
 #ifdef V8_ENABLE_SANDBOX_HARDWARE_SUPPORT
   // The actual stack memory must be accessible to sandboxed code, so we need
   // to register it as sandbox extension memory here.
