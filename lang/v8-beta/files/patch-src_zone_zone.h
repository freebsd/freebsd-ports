--- src/zone/zone.h.orig	2026-09-07 08:43:04 UTC
+++ src/zone/zone.h
@@ -225,9 +225,12 @@ class V8_EXPORT_PRIVATE Zone final {
   // (e.g. tracking allocated bytes, maintaining linked lists, etc).
   void ReleaseSegment(Segment* segment);
 
-  // All pointers returned from New() are 8-byte aligned.
-  // ASan requires 8-byte alignment. MIPS also requires 8-byte alignment.
-  static const size_t kAlignmentInBytes = 8;
+  // All pointers returned from New() are aligned to the platform's maximum
+  // fundamental alignment (alignof(std::max_align_t)), which is 16 bytes on
+  // 64-bit FreeBSD/LLVM where std::function and similar types require 16-byte
+  // alignment. The original value of 8 is sufficient for Linux/glibc but not
+  // for FreeBSD with system libc++.
+  static const size_t kAlignmentInBytes = alignof(std::max_align_t);
 
   // Never allocate segments smaller than this size in bytes.
   static const size_t kMinimumSegmentSize = 8 * KB;
