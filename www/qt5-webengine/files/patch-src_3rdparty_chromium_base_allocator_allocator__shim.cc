--- src/3rdparty/chromium/base/allocator/allocator_shim.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/base/allocator/allocator_shim.cc
@@ -69,7 +69,7 @@ inline const allocator::AllocatorDispatch* GetChainHea
   // Unfortunately due to that bug NoBarrier_Load() is mistakenly fully
   // barriered on Linux+Clang, and that causes visible perf regressons.
   return reinterpret_cast<const allocator::AllocatorDispatch*>(
-#if defined(OS_LINUX) && defined(__clang__)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && defined(__clang__)
       *static_cast<const volatile subtle::AtomicWord*>(&g_chain_head)
 #else
       subtle::NoBarrier_Load(&g_chain_head)
