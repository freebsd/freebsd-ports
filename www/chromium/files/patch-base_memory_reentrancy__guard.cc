--- base/memory/reentrancy_guard.cc.orig	2026-11-19 12:25:27 UTC
+++ base/memory/reentrancy_guard.cc
@@ -9,7 +9,7 @@
 
 namespace base::internal {
 
-#if PA_BUILDFLAG(IS_LINUX) || PA_BUILDFLAG(IS_CHROMEOS)
+#if PA_BUILDFLAG(IS_LINUX) || PA_BUILDFLAG(IS_CHROMEOS) || PA_BUILDFLAG(IS_BSD)
 std::atomic<int> ReentrancyState::Guard::guard_count_{0};
 std::array<std::atomic<ReentrancyState::PlatformThreadRef>,
            ReentrancyState::Guard::kCapacity>
