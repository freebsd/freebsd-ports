--- v8/src/base/platform/platform-posix.cc.orig	2022-02-07 13:39:41 UTC
+++ v8/src/base/platform/platform-posix.cc
@@ -65,7 +65,7 @@
 #include <sys/syscall.h>
 #endif
 
-#if V8_OS_FREEBSD || V8_OS_MACOSX || V8_OS_OPENBSD || V8_OS_SOLARIS
+#if V8_OS_FREEBSD || V8_OS_MACOSX || V8_OS_BSD || V8_OS_SOLARIS
 #define MAP_ANONYMOUS MAP_ANON
 #endif
 
@@ -285,8 +285,15 @@ void OS::SetRandomMmapSeed(int64_t seed) {
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
@@ -377,6 +384,7 @@ void* OS::GetRandomMmapAddr() {
 #endif
   return reinterpret_cast<void*>(raw_addr);
 }
+#endif
 
 // TODO(bbudge) Move Cygwin and Fuchsia stuff into platform-specific files.
 #if !V8_OS_CYGWIN && !V8_OS_FUCHSIA
@@ -547,7 +555,7 @@ bool OS::FreeAddressSpaceReservation(AddressSpaceReser
 
 // static
 bool OS::HasLazyCommits() {
-#if V8_OS_AIX || V8_OS_LINUX || V8_OS_MACOSX
+#if V8_OS_AIX || V8_OS_LINUX || V8_OS_MACOSX || V8_OS_BSD
   return true;
 #else
   // TODO(bbudge) Return true for all POSIX platforms.
@@ -1140,7 +1148,7 @@ void Thread::SetThreadLocal(LocalStorageKey key, void*
 // keep this version in POSIX as most Linux-compatible derivatives will
 // support it. MacOS and FreeBSD are different here.
 #if !defined(V8_OS_FREEBSD) && !defined(V8_OS_MACOSX) && !defined(_AIX) && \
-    !defined(V8_OS_SOLARIS)
+    !defined(V8_OS_SOLARIS) && !defined(V8_OS_OPENBSD)
 
 // static
 Stack::StackSlot Stack::GetStackStart() {
