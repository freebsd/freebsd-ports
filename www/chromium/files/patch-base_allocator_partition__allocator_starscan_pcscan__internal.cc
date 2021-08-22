--- base/allocator/partition_allocator/starscan/pcscan_internal.cc.orig	2021-07-28 07:02:32 UTC
+++ base/allocator/partition_allocator/starscan/pcscan_internal.cc
@@ -72,7 +72,7 @@ namespace internal {
 
 namespace {
 
-#if DCHECK_IS_ON() && defined(OS_LINUX)
+#if DCHECK_IS_ON() && (defined(OS_LINUX) || defined(OS_BSD))
 // Currently, check reentracy only on Linux. On Android TLS is emulated by the
 // runtime lib, which can allocate and therefore cause reentrancy.
 struct ReentrantScannerGuard final {
