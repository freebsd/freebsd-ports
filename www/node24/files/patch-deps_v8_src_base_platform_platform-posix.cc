--- deps/v8/src/base/platform/platform-posix.cc.orig	2025-07-15 17:11:17 UTC
+++ deps/v8/src/base/platform/platform-posix.cc
@@ -360,6 +360,9 @@ void* OS::GetRandomMmapAddr() {
   raw_addr &= uint64_t{0x3FFFF000};
   // Use extra address space to isolate the mmap regions.
   raw_addr += uint64_t{0x400000000000};
+#elif V8_TARGET_BIG_ENDIAN
+  // Big-endian Linux: 42 bits of virtual addressing.
+  raw_addr &= uint64_t{0x03FFFFFFF000};
 #else
   // Little-endian Linux: 46 bits of virtual addressing.
   raw_addr &= uint64_t{0x3FFFFFFF0000};
