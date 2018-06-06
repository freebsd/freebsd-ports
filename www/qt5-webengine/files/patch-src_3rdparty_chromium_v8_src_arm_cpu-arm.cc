--- src/3rdparty/chromium/v8/src/arm/cpu-arm.cc.orig	2017-09-25 11:16:57 UTC
+++ src/3rdparty/chromium/v8/src/arm/cpu-arm.cc
@@ -17,6 +17,11 @@
 #include "src/assembler.h"
 #include "src/macro-assembler.h"
 
+#if V8_OS_FREEBSD
+#include <sys/types.h>
+#include <machine/sysarch.h>
+#endif
+
 namespace v8 {
 namespace internal {
 
@@ -24,6 +29,8 @@ void CpuFeatures::FlushICache(void* start, size_t size
 #if !defined(USE_SIMULATOR)
 #if V8_OS_QNX
   msync(start, size, MS_SYNC | MS_INVALIDATE_ICACHE);
+#elif V8_OS_FREEBSD
+  __clear_cache(start, reinterpret_cast<char*>(start) + size);
 #else
   register uint32_t beg asm("r0") = reinterpret_cast<uint32_t>(start);
   register uint32_t end asm("r1") = beg + size;
