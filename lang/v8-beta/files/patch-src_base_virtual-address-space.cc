--- src/base/virtual-address-space.cc.orig	2026-09-30 05:49:42 UTC
+++ src/base/virtual-address-space.cc
@@ -12,6 +12,10 @@
 #include "src/base/bits.h"
 #include "src/base/platform/platform.h"
 
+#if V8_OS_FREEBSD
+#include <sys/mman.h>
+#endif
+
 namespace v8 {
 namespace base {
 
@@ -99,12 +103,22 @@ bool VirtualAddressSpace::AllocateGuardRegion(Address 
   DCHECK(IsAligned(size, allocation_granularity()));
 
   void* hint = reinterpret_cast<void*>(address);
+#if V8_OS_FREEBSD
+  // With ASLR enabled, FreeBSD shifts non-fixed mappings by a random offset
+  // even when the hinted range is free, so the hint is never honored. Use
+  // MAP_FIXED | MAP_EXCL instead: the mapping is placed exactly at the hint,
+  // and the request fails (rather than replacing) if the range is in use.
+  void* result = mmap(hint, size, PROT_NONE,
+                      MAP_PRIVATE | MAP_ANON | MAP_FIXED | MAP_EXCL, -1, 0);
+  return result != MAP_FAILED;
+#else
   void* result = OS::Allocate(hint, size, allocation_granularity(),
                               OS::MemoryPermission::kNoAccess);
   if (result && result != hint) {
     OS::Free(result, size);
   }
   return result == hint;
+#endif
 }
 
 void VirtualAddressSpace::FreeGuardRegion(Address address, size_t size) {
