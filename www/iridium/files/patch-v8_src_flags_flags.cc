--- v8/src/flags/flags.cc.orig	2024-08-01 05:47:53 UTC
+++ v8/src/flags/flags.cc
@@ -15,6 +15,10 @@
 #include <set>
 #include <sstream>
 
+#if V8_OS_OPENBSD
+#include <sys/mman.h>
+#endif
+
 #include "src/base/functional.h"
 #include "src/base/lazy-instance.h"
 #include "src/base/platform/platform.h"
@@ -34,7 +38,11 @@
 namespace v8::internal {
 
 // Define {v8_flags}, declared in flags.h.
+#if V8_OS_OPENBSD
+FlagValues v8_flags __attribute__((section(".openbsd.mutable")));
+#else
 FlagValues v8_flags;
+#endif
 
 // {v8_flags} needs to be aligned to a memory page, and the size needs to be a
 // multiple of a page size. This is required for memory-protection of the memory
@@ -806,6 +814,10 @@ void FlagList::FreezeFlags() {
   // Note that for string flags we only protect the pointer itself, but not the
   // string storage. TODO(12887): Fix this.
   base::OS::SetDataReadOnly(&v8_flags, sizeof(v8_flags));
+#if V8_OS_OPENBSD
+  if (mimmutable(&v8_flags, sizeof(v8_flags)) == -1)
+    FATAL("unable to set immutability of v8_flags");
+#endif
 }
 
 // static
