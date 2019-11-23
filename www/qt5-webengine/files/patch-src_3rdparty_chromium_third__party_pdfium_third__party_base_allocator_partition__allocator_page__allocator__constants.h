--- src/3rdparty/chromium/third_party/pdfium/third_party/base/allocator/partition_allocator/page_allocator_constants.h.orig	2019-05-23 14:39:34.000000000 +0200
+++ src/3rdparty/chromium/third_party/pdfium/third_party/base/allocator/partition_allocator/page_allocator_constants.h	2019-10-29 15:25:35.191867000 +0100
@@ -13,7 +13,7 @@
 namespace base {
 #if defined(OS_WIN)
 static constexpr size_t kPageAllocationGranularityShift = 16;  // 64KB
-#elif defined(_MIPS_ARCH_LOONGSON)
+#elif defined(_MIPS_ARCH_LOONGSON) || defined(ARCH_CPU_PPC64)
 static constexpr size_t kPageAllocationGranularityShift = 14;  // 16KB
 #else
 static constexpr size_t kPageAllocationGranularityShift = 12;  // 4KB
