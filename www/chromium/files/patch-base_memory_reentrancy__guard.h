--- base/memory/reentrancy_guard.h.orig	2026-11-19 12:25:27 UTC
+++ base/memory/reentrancy_guard.h
@@ -50,7 +50,7 @@ struct BASE_EXPORT ReentrancyState {
 #endif
   static inline constexpr TlsKey kInvalidTlsKey = static_cast<TlsKey>(-1);
 
-#if PA_BUILDFLAG(IS_LINUX) || PA_BUILDFLAG(IS_CHROMEOS)
+#if PA_BUILDFLAG(IS_LINUX) || PA_BUILDFLAG(IS_CHROMEOS) || PA_BUILDFLAG(IS_BSD)
   struct FastHasher {
     NO_SANITIZE("address")
     size_t operator()(uintptr_t value) const {
@@ -139,7 +139,7 @@ struct BASE_EXPORT ReentrancyState {
 
   NO_SANITIZE("address")
   PA_ALWAYS_INLINE static void Initialize(PlatformThreadRef thread_ref) {
-#if PA_BUILDFLAG(IS_LINUX) || PA_BUILDFLAG(IS_CHROMEOS)
+#if PA_BUILDFLAG(IS_LINUX) || PA_BUILDFLAG(IS_CHROMEOS) || PA_BUILDFLAG(IS_BSD)
     // (1) this thread has not initialized the thread local variable yet.
     // The first pthread_setspecific() may cause memory allocation.
     Guard guard_scope(thread_ref);
@@ -201,7 +201,7 @@ struct BASE_EXPORT ReentrancyState {
     auto reentrancy_guard_state = GetState();
     if (reentrancy_guard_state != Value::kInitialized) [[unlikely]] {
       if (reentrancy_guard_state == Value::kUninitialized) [[likely]] {
-#if PA_BUILDFLAG(IS_LINUX) || PA_BUILDFLAG(IS_CHROMEOS)
+#if PA_BUILDFLAG(IS_LINUX) || PA_BUILDFLAG(IS_CHROMEOS) || PA_BUILDFLAG(IS_BSD)
         // `kUninitialized` means (1) this thread has not initialized the thread
         // local variable yet or (2) pthread_setspecific() for the
         // initialization causes memory allocation and reentrancy.
