--- v8/src/base/platform/platform-posix.cc.orig	2024-08-26 12:06:38 UTC
+++ v8/src/base/platform/platform-posix.cc
@@ -54,7 +54,7 @@
 #if V8_OS_DARWIN
 #include <mach/mach.h>
 #include <malloc/malloc.h>
-#elif !V8_OS_ZOS
+#elif !V8_OS_ZOS && !V8_OS_BSD
 #include <malloc.h>
 #endif
 
@@ -72,7 +72,7 @@
 #include <sys/syscall.h>
 #endif
 
-#if V8_OS_FREEBSD || V8_OS_DARWIN || V8_OS_OPENBSD || V8_OS_SOLARIS
+#if V8_OS_FREEBSD || V8_OS_DARWIN || V8_OS_BSD || V8_OS_SOLARIS
 #define MAP_ANONYMOUS MAP_ANON
 #endif
 
@@ -311,8 +311,15 @@ void OS::SetRandomMmapSeed(int64_t seed) {
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
@@ -407,6 +414,7 @@ void* OS::GetRandomMmapAddr() {
 #endif
   return reinterpret_cast<void*>(raw_addr);
 }
+#endif
 
 // TODO(bbudge) Move Cygwin and Fuchsia stuff into platform-specific files.
 #if !V8_OS_CYGWIN && !V8_OS_FUCHSIA
@@ -681,7 +689,7 @@ void OS::DestroySharedMemoryHandle(PlatformSharedMemor
 #if !V8_OS_ZOS
 // static
 bool OS::HasLazyCommits() {
-#if V8_OS_AIX || V8_OS_LINUX || V8_OS_DARWIN
+#if V8_OS_AIX || V8_OS_LINUX || V8_OS_DARWIN || V8_OS_BSD
   return true;
 #else
   // TODO(bbudge) Return true for all POSIX platforms.
@@ -1326,7 +1334,7 @@ void Thread::SetThreadLocal(LocalStorageKey key, void*
 // keep this version in POSIX as most Linux-compatible derivatives will
 // support it. MacOS and FreeBSD are different here.
 #if !defined(V8_OS_FREEBSD) && !defined(V8_OS_DARWIN) && !defined(_AIX) && \
-    !defined(V8_OS_SOLARIS)
+    !defined(V8_OS_SOLARIS) && !defined(V8_OS_OPENBSD)
 
 namespace {
 #if DEBUG
