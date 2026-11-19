--- v8/src/base/platform/platform-posix.cc.orig	2026-11-19 12:25:27 UTC
+++ v8/src/base/platform/platform-posix.cc
@@ -77,7 +77,7 @@
 #include <sys/syscall.h>
 #endif
 
-#if V8_OS_FREEBSD || V8_OS_DARWIN || V8_OS_OPENBSD || V8_OS_SOLARIS
+#if V8_OS_FREEBSD || V8_OS_DARWIN || V8_OS_BSD || V8_OS_SOLARIS
 #define MAP_ANONYMOUS MAP_ANON
 #endif
 
@@ -370,8 +370,15 @@ void OS::SetRandomMmapSeed(int64_t seed) {
   }
 }
 
+#if V8_OS_OPENBSD
+// Allow OpenBSD's mmap to select a random address on OpenBSD 
 // static
 void* OS::GetRandomMmapAddr() {
+  return nullptr;
+}
+#else
+// static
+void* OS::GetRandomMmapAddr() {
   uintptr_t raw_addr;
   {
     MutexGuard guard(rng_mutex.Pointer());
@@ -468,6 +475,7 @@ void* OS::GetRandomMmapAddr() {
 #endif
   return reinterpret_cast<void*>(raw_addr);
 }
+#endif
 
 // TODO(bbudge) Move Cygwin and Fuchsia stuff into platform-specific files.
 #if !V8_OS_CYGWIN && !V8_OS_FUCHSIA
@@ -783,7 +791,7 @@ void OS::DestroySharedMemoryHandle(SharedMemoryHandle 
 #if !V8_OS_ZOS
 // static
 bool OS::HasLazyCommits() {
-#if V8_OS_AIX || V8_OS_LINUX || V8_OS_DARWIN
+#if V8_OS_AIX || V8_OS_LINUX || V8_OS_DARWIN || V8_OS_BSD
   return true;
 #else
   // TODO(bbudge) Return true for all POSIX platforms.
@@ -1426,7 +1434,7 @@ void Thread::SetThreadLocal(LocalStorageKey key, void*
 // keep this version in POSIX as most Linux-compatible derivatives will
 // support it. MacOS and FreeBSD are different here.
 #if !defined(V8_OS_FREEBSD) && !defined(V8_OS_DARWIN) && !defined(_AIX) && \
-    !defined(V8_OS_SOLARIS)
+    !defined(V8_OS_SOLARIS) && !defined(V8_OS_OPENBSD)
 
 namespace {
 #if DEBUG
@@ -1488,19 +1496,13 @@ Stack::StackSlot Stack::ObtainCurrentThreadStackStart(
   return stack_start;
 #endif  // V8_OS_ZOS
 }
+#endif  // !defined(V8_OS_FREEBSD) && !defined(V8_OS_DARWIN) &&
+        // !defined(_AIX) && !defined(V8_OS_SOLARIS)
 
 // static
 Stack::StackSlot Stack::ObtainCurrentThreadStackReservedLimit() {
 #if V8_OS_ZOS
   return nullptr;
-#elif V8_OS_OPENBSD
-  stack_t stack;
-  int error = pthread_stackseg_np(pthread_self(), &stack);
-  if (error) {
-    DCHECK(MainThreadIsCurrentThread());
-    return nullptr;
-  }
-  return stack.ss_sp;
 #else
 // For most libcs, pthread_getattr_np() returns the the stack reserved
 // limit on the main thread, but musl only returns the current high-water
@@ -1511,7 +1513,11 @@ Stack::StackSlot Stack::ObtainCurrentThreadStackReserv
   if (syscall(__NR_gettid) == getpid()) return nullptr;
 #endif
   pthread_attr_t attr;
+#if V8_OS_BSD
+  int error = pthread_attr_init(&attr);
+#else
   int error = pthread_getattr_np(pthread_self(), &attr);
+#endif
   if (error) {
     DCHECK(MainThreadIsCurrentThread());
     return nullptr;
@@ -1524,10 +1530,6 @@ Stack::StackSlot Stack::ObtainCurrentThreadStackReserv
   return base;
 #endif  // V8_OS_ZOS
 }
-
-#endif  // !defined(V8_OS_FREEBSD) && !defined(V8_OS_DARWIN) &&
-        // !defined(_AIX) && !defined(V8_OS_SOLARIS)
-
 
 
 // static
