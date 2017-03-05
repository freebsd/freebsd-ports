--- base/allocator/allocator_shim.cc.orig	2017-02-02 02:02:47 UTC
+++ base/allocator/allocator_shim.cc
@@ -89,7 +89,7 @@ inline const allocator::AllocatorDispatc
   // Unfortunately due to that bug NoBarrier_Load() is mistakenly fully
   // barriered on Linux+Clang, and that causes visible perf regressons.
   return reinterpret_cast<const allocator::AllocatorDispatch*>(
-#if defined(OS_LINUX) && defined(__clang__)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && defined(__clang__)
       *static_cast<const volatile subtle::AtomicWord*>(&g_chain_head)
 #else
       subtle::NoBarrier_Load(&g_chain_head)
